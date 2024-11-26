import { NgClass, NgFor } from '@angular/common';
import { Component, EventEmitter, Input, Output } from '@angular/core';


@Component({
  selector: 'app-topbar',
  templateUrl: './topbar.component.html',
  styleUrls: ['./topbar.component.scss'],
  standalone: true,
  imports: [NgClass,NgFor],
})
export class TopbarComponent {
  @Input() selectedDay: string = '';
  @Input() selectedTime: string = '';
  @Output() dayChange = new EventEmitter<any>();
  @Output() timeChange = new EventEmitter<any>();
  @Output() roomSearch = new EventEmitter<any>();

  days = ['MON', 'TUE', 'WED', 'THU', 'FRI'];
  times = ['8-9AM', '9-10AM', '10-11AM', '11-12PM', '12-1PM', '2-3PM', '3-4PM', '4-5PM', '5-6PM'];
}
