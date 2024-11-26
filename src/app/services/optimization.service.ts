// src/app/services/optimization.service.ts

import { Injectable } from '@angular/core';

type WeekDays = 'MON' | 'TUE' | 'WED' | 'THU' | 'FRI';

@Injectable({
  providedIn: 'root'
})
export class OptimizationService {

  // Rooms data (sample data for NR and NC rooms)
  rooms = [
    { roomId: 'NR101', capacity: 100, availability: this.createWeekAvailability() },
    { roomId: 'NR102', capacity: 50, availability: this.createWeekAvailability() },
    { roomId: 'NC201', capacity: 80, availability: this.createWeekAvailability() },
    { roomId: 'NC202', capacity: 40, availability: this.createWeekAvailability() },
    // Add more rooms as needed
  ];

  // Utility to initialize availability for each room
  private createWeekAvailability(): Record<WeekDays, boolean[]> {
    return {
      MON: Array(9).fill(false),
      TUE: Array(9).fill(false),
      WED: Array(9).fill(false),
      THU: Array(9).fill(false),
      FRI: Array(9).fill(false)
    };
  }

  // Function to assign students to rooms
  allocateStudentsToRooms(totalStudents: number): any[] {
    const allocations = [];
    let remainingStudents = totalStudents;
    const roomsToConsider = this.rooms.filter(room => room.roomId.startsWith('NR') || room.roomId.startsWith('NC'));

    for (const room of roomsToConsider) {
      if (remainingStudents <= 0) break;

      const availableSlot = this.findAvailableSlot(room);

      if (availableSlot !== null) {
        if (room.capacity >= remainingStudents) {
          allocations.push({
            roomId: room.roomId,
            capacity: room.capacity,
            allocatedStudents: remainingStudents,
            day: availableSlot.day,
            time: availableSlot.slot
          });

          // Mark the room slot as occupied
          room.availability[availableSlot.day][availableSlot.slot] = true;
          remainingStudents = 0; // All students are allocated
        } else if (room.capacity < remainingStudents) {
          allocations.push({
            roomId: room.roomId,
            capacity: room.capacity,
            allocatedStudents: room.capacity,
            day: availableSlot.day,
            time: availableSlot.slot
          });

          // Mark the room slot as occupied
          room.availability[availableSlot.day][availableSlot.slot] = true;
          remainingStudents -= room.capacity; // Reduce remaining students
        }
      }
    }

    return allocations;
  }

  // Find an available time slot for a room
  private findAvailableSlot(room: any): { day: WeekDays, slot: number } | null {
    const days: WeekDays[] = ['MON', 'TUE', 'WED', 'THU', 'FRI'];
    for (const day of days) {
      for (let slot = 0; slot < room.availability[day].length; slot++) {
        if (!room.availability[day][slot]) {
          return { day, slot };
        }
      }
    }
    return null; // No available slot found
  }
}
