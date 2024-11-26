import { Component, OnInit, Input, OnChanges, SimpleChanges } from '@angular/core';
import { FreeRoomService } from '../services/free-room.service';
import { Chart } from 'chart.js/auto';

@Component({
  selector: 'app-utilization-metrics',
  templateUrl: './metrics.component.html',
  styleUrls: ['./metrics.component.scss'],
  standalone: true,
})
export class UtilizationMetricsComponent implements OnInit, OnChanges {
  @Input() selectedDay: string = ''; // Input property to receive the selected day
  utilizationData: { time: string; count: number }[] = [];
  chart: any;
  mostAvailableSlot: string = ''; // Slot with the most availability
  leastAvailableSlot: string = ''; // Slot with the least availability

  constructor(private freeRoomService: FreeRoomService) {}

  ngOnInit() {
    this.loadMetricsData();
  }

  ngOnChanges(changes: SimpleChanges) {
    if (changes['selectedDay'] && !changes['selectedDay'].firstChange) {
      this.loadMetricsData(); // Reload the data when selectedDay changes
    }
  }

  async loadMetricsData() {
    if (!this.selectedDay) return; // Check if the selected day is set
    const times = ['8-9AM', '9-10AM', '10-11AM', '11-12AM', '12-1PM', '2-3PM', '3-4PM', '4-5PM', '5-6PM'];
    const aggregatedData: { time: string; count: number }[] = times.map(time => ({ time, count: 0 }));

    try {
      for (let i = 0; i < times.length; i++) {
        const data = await this.freeRoomService.getFreeRooms(this.selectedDay, i);
        aggregatedData[i].count = data.time.length; // Replace count, no need to accumulate here
      }

      this.utilizationData = aggregatedData;
      this.findMostAndLeastAvailableSlots(); // Calculate most/least available slots
      this.updateChart();
    } catch (error) {
      console.error('Failed to load utilization data:', error);
    }
  }

  findMostAndLeastAvailableSlots() {
    if (this.utilizationData.length === 0) return;

    // Find max and min availability counts
    const maxSlot = this.utilizationData.reduce((prev, curr) => (curr.count > prev.count ? curr : prev));
    const minSlot = this.utilizationData.reduce((prev, curr) => (curr.count < prev.count ? curr : prev));

    this.mostAvailableSlot = maxSlot.time;
    this.leastAvailableSlot = minSlot.time;
  }

  updateChart() {
    if (this.chart) {
      this.chart.destroy(); // Destroy existing chart before creating a new one
    }
  
    // Define a set of vibrant colors for the chart bars
    const colors = [
      'rgba(255, 99, 132, 0.8)',   // Bright pink
      'rgba(54, 162, 235, 0.8)',   // Bright blue
      'rgba(255, 206, 86, 0.8)',   // Vibrant yellow
      'rgba(75, 192, 192, 0.8)',   // Teal
      'rgba(153, 102, 255, 0.8)',  // Lavender
      'rgba(255, 159, 64, 0.8)',   // Bright orange
      'rgba(199, 100, 234, 0.8)',  // Purple-pink
      'rgba(255, 140, 190, 0.8)',  // Soft coral
      'rgba(144, 238, 144, 0.8)'   // Light green
    ];
  
    this.chart = new Chart('utilizationChart', {
      type: 'bar',
      data: {
        labels: this.utilizationData.map(data => data.time),
        datasets: [
          {
            label: 'Available Room Count',
            data: this.utilizationData.map(data => data.count),
            backgroundColor: colors.slice(0, this.utilizationData.length), // Apply colors based on data length
          },
        ],
      },
      options: {
        responsive: true,
        plugins: {
          legend: {
            display: true,
            labels: {
              color: '#d1d0c5', // Match the font color to your page style
            },
          },
        },
        scales: {
          x: {
            ticks: {
              color: '#d1d0c5', // Adjust X-axis tick color
            },
          },
          y: {
            ticks: {
              color: '#d1d0c5', // Adjust Y-axis tick color
            },
          },
        },
      },
    });
  }
  
}
