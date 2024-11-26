import { Component, Input, OnChanges, SimpleChanges } from '@angular/core';
import { DecimalPipe, NgFor, NgIf } from '@angular/common';

@Component({
  selector: 'app-room-metrics',
  templateUrl: './room-metrics.component.html',
  styleUrls: ['./room-metrics.component.scss'],
  standalone: true,
  imports: [NgFor, NgIf, DecimalPipe]
})
export class RoomMetricsComponent implements OnChanges {
  @Input() roomAllocation: { [key: string]: string[] } = {};
  @Input() totalRooms: number = 0;

  occupancyRate: number = 0;
  allocationEfficiency: number = 0;
  peakUsageRooms: number = 0;
  unutilizedRooms: number = 0;

  get objectKeys() {
    return Object.keys;
  }

  ngOnChanges(changes: SimpleChanges): void {
    if (changes['roomAllocation'] || changes['totalRooms']) {
      this.calculateMetrics();
    }
  }

  calculateMetrics(): void {
    const totalAllocatedSeats = Object.values(this.roomAllocation).reduce((sum, seats) => sum + seats.length, 0);
    const totalCapacity = this.totalRooms * 50;

    this.occupancyRate = (totalAllocatedSeats / totalCapacity) * 100;
    this.allocationEfficiency = (Object.keys(this.roomAllocation).length / this.totalRooms) * 100;
    this.peakUsageRooms = Object.values(this.roomAllocation).filter(seats => seats.length >= 40).length;
    this.unutilizedRooms = this.totalRooms - Object.keys(this.roomAllocation).length;
  }
}
