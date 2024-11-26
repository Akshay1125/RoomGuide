import { Component, OnInit, Inject, Renderer2, PLATFORM_ID } from '@angular/core';
import { isPlatformBrowser } from '@angular/common'; // import this function for platform check
import { FreeRoomService } from '../services/free-room.service';
import { RoomComponent } from '../components/room/room.component';
import { FooterComponent } from '../components/footer/footer.component';
import { TopbarComponent } from '../components/topbar/topbar.component';
import { HttpClient, HttpClientModule } from '@angular/common/http';
import { NgFor } from '@angular/common';
import { UtilizationMetricsComponent } from '../metrics/metrics.component';
import { OptimizationComponent } from '../components/optimization/optimization.component';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss'],
  standalone: true,
  imports: [NgFor, RoomComponent, FooterComponent, TopbarComponent,  UtilizationMetricsComponent, OptimizationComponent],
  providers: [HttpClient]
})
export class HomeComponent implements OnInit {
  days: string[] = ['MON', 'TUE', 'WED', 'THU', 'FRI'];
  times: string[] = ['8-9AM', '9-10AM', '10-11AM', '11-12PM', '12-1PM', '2-3PM', '3-4PM', '4-5PM', '5-6PM'];
  freeRooms: string[] = []; 
  ncRooms: string[] = [];
  nrRooms: string[] = [];
  filteredFreeRooms: string[] = [];
  selectedDay: string = '';
  selectedTime: string = '8-9AM';
  roomName: string = '';

  isDarkMode: boolean = true; // Default to dark mode

  constructor(
    private freeRoomService: FreeRoomService,
    private renderer: Renderer2,
    @Inject(PLATFORM_ID) private platformId: object // Inject platform ID to check if we’re in browser
  ) {}

  ngOnInit() {
    this.applyTheme();
  }

  toggleTheme(): void {
    this.isDarkMode = !this.isDarkMode;
    this.applyTheme();
  }

  applyTheme(): void {
    if (isPlatformBrowser(this.platformId)) {
      const body = this.renderer.selectRootElement('body', true); // Ensure it's selecting the body
      if (this.isDarkMode) {
        this.renderer.addClass(body, 'home-dark-theme');
        this.renderer.removeClass(body, 'home-light-theme');
      } else {
        this.renderer.addClass(body, 'home-light-theme');
        this.renderer.removeClass(body, 'home-dark-theme');
      }
    }
  }

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

        // Separate rooms into NC and NR
        this.ncRooms = this.freeRooms.filter(room => room.startsWith('NC'));
        //sort ncrooms
        this.ncRooms.sort();
        this.nrRooms = this.freeRooms.filter(room => room.startsWith('NR'));
        this.nrRooms.sort();


        


        this.filteredFreeRooms = this.ncRooms.concat(this.nrRooms);
      } catch (error) {
        console.error('Failed to fetch rooms:', error);
      }
    }
  }
}
