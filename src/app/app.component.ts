import { Component, OnInit } from '@angular/core';
import { FreeRoomService } from './services/free-room.service';
import { RoomComponent } from './components/room/room.component';
import { FooterComponent } from './components/footer/footer.component';
import { TopbarComponent } from './components/topbar/topbar.component';
import { HttpClient, HttpClientModule } from '@angular/common/http';
import { NgFor } from '@angular/common';
import { HomeComponent } from './home/home.component';
import { HomepageComponent } from './homepage/homepage.component';
import { Router } from '@angular/router';
import { RouterOutlet } from '@angular/router';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
  standalone: true,
  imports: [NgFor,RoomComponent, FooterComponent, TopbarComponent, HttpClientModule, HomeComponent, HomepageComponent,RouterOutlet ],
  providers: [HttpClient],

})
export class AppComponent implements OnInit {
  days: string[] = ['MON', 'TUE', 'WED', 'THU', 'FRI'];
  times: string[] = ['8-9AM', '9-10AM', '10-11AM', '11-12PM', '12-1PM', '2-3PM', '3-4PM', '4-5PM', '5-6PM'];
  freeRooms: string[] = []; 
  filteredFreeRooms: string[] = [];
  selectedDay: string = '';
  selectedTime: string = '8-9AM';
  roomName: string = '';

  constructor(private freeRoomService: FreeRoomService) {}

  ngOnInit() {}

  handleSelectChangeDay(event: any): void {
    this.selectedDay = event.target.value;
    this.fetchFreeRooms();
  }

  handleSelectChangeTime(event: any): void {
    this.selectedTime = event.target.value;
    this.fetchFreeRooms();
  }

  handleSelectChangeRoom(event: any): void {
    this.roomName = event.target.value;
    if (this.roomName) {
      this.filteredFreeRooms = this.freeRooms.filter(room => room.toUpperCase().includes(this.roomName.toUpperCase()));
    } else {
      this.filteredFreeRooms = this.freeRooms;
    }
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
        this.filteredFreeRooms = this.freeRooms;
      } catch (error) {
        console.error('Failed to fetch rooms:', error);
      }
    }
  }
}