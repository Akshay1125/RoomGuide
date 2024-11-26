import { Component, OnInit } from '@angular/core';
import { FreeRoomService } from '../../services/free-room.service';
import { RoomMetricsComponent } from '../../room-metrics/room-metrics.component';
import { FormsModule } from '@angular/forms';
import { NgFor, NgIf } from '@angular/common';

@Component({
  selector: 'app-optimization',
  templateUrl: './optimization.component.html',
  styleUrls: ['./optimization.component.scss'],
  standalone: true,
  imports: [FormsModule, NgFor, NgIf, RoomMetricsComponent]
})
export class OptimizationComponent implements OnInit {
  days: string[] = ['MON', 'TUE', 'WED', 'THU', 'FRI'];
  times: string[] = ['8-9AM', '9-10AM', '10-11AM', '11-12PM', '12-1PM', '2-3PM', '3-4PM', '4-5PM', '5-6PM'];
  freeRooms: string[] = [];
  ncRooms: string[] = [];
  nrRooms: string[] = [];
  filteredFreeRooms: string[] = [];
  selectedDay: string = '';
  selectedTime: string = '8-9AM';
  totalStudents: number = 0;
  roomAllocation: { [key: string]: string[] } = {}; 
  totalRooms: number = 0; // Total rooms available

  constructor(private freeRoomService: FreeRoomService) {}

  ngOnInit() {
    this.fetchFreeRooms();
  }

  getTimeIndex(time: string): number {
    return this.times.indexOf(time);
  }
  async fetchFreeRooms(): Promise<void> {
    const timeIndex = this.getTimeIndex(this.selectedTime);

    if (this.selectedDay && timeIndex !== -1) {
      try {
        const data = await this.freeRoomService.getFreeRooms(this.selectedDay, timeIndex);
        this.freeRooms = data.time;
        
        // Helper function to get floor number from room name
        const getFloorNumber = (room: string): number => {
          const match = room.match(/\d/);
          return match ? parseInt(match[0]) : 0;
        };

        // Helper function to sort rooms on the same floor
        const sortRoomsOnSameFloor = (a: string, b: string): number => {
          // If room numbers exist after the floor number (e.g., NR101, NC102)
          const aRoom = parseInt(a.replace(/[^\d]/g, ''));
          const bRoom = parseInt(b.replace(/[^\d]/g, ''));
          return aRoom - bRoom;
        };

        // Separate and sort NR and NC rooms by floor
        const sortedRooms: string[] = [];
        
        // Get all unique floor numbers
        const floors = [...new Set(this.freeRooms.map(getFloorNumber))].sort();
        
        // For each floor, add NR rooms then NC rooms
        floors.forEach(floor => {
          // Get and sort NR rooms for this floor
          const nrRoomsOnFloor = this.freeRooms
            .filter(room => room.startsWith('NR') && getFloorNumber(room) === floor)
            .sort(sortRoomsOnSameFloor);
          
          // Get and sort NC rooms for this floor
          const ncRoomsOnFloor = this.freeRooms
            .filter(room => room.startsWith('NC') && getFloorNumber(room) === floor)
            .sort(sortRoomsOnSameFloor);
          
          // Add rooms to final array
          sortedRooms.push(...nrRoomsOnFloor, ...ncRoomsOnFloor);
        });

        this.filteredFreeRooms = sortedRooms;
        this.nrRooms = sortedRooms.filter(room => room.startsWith('NR'));
        this.ncRooms = sortedRooms.filter(room => room.startsWith('NC'));
        this.totalRooms = this.filteredFreeRooms.length;
        
      } catch (error) {
        console.error('Failed to fetch rooms:', error);
      }
    }
  }

  allocateStudents(): void {
    if (this.totalStudents <= 0 || this.filteredFreeRooms.length === 0) {
      console.log("Invalid number of students or no available rooms");
      return;
    }

    let roomsToAllocate = [...this.filteredFreeRooms]; // Already sorted floor-wise
    let remainingStudents = this.totalStudents;
    let allocationResult: { [key: string]: string[] } = {};

    roomsToAllocate.forEach(room => {
      if (remainingStudents > 0) {
        let roomCapacity = room.startsWith('NC') ? 46 : 84;
        let allocatedStudents = Math.min(roomCapacity, remainingStudents);
        allocationResult[room] = Array(allocatedStudents).fill('Student');
        remainingStudents -= allocatedStudents;
      }
    });

    this.roomAllocation = allocationResult;
  }
}