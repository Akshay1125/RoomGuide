import { Component } from '@angular/core';
import { Router, Routes } from '@angular/router';

@Component({
  selector: 'app-homepage',
  standalone: true,
  imports: [],
  templateUrl: './homepage.component.html',
  styleUrls: ['./homepage.component.scss']
})
export class HomepageComponent {
  
  constructor(private router: Router) {}

  goToHomePage(): void {
    this.router.navigate(['/home']);
  }
  goToRoute(): void {
    this.router.navigate(['/path']);
  }
  goToContactPage(): void {
    this.router.navigate(['/contact']);
  }
}
