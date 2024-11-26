import { Routes } from '@angular/router';
import { HomepageComponent } from './homepage/homepage.component';
import { HomeComponent } from './home/home.component';
import { PathComponent } from './path/path.component';
import { ContactComponent } from './contact/contact.component';
import { RoomMetricsComponent } from './room-metrics/room-metrics.component';
export const routes: Routes = [
    { path: '', component: HomepageComponent },  // Default path
    { path: 'home', component: HomeComponent },
    { path: 'path', component: PathComponent },
    {path : 'contact', component : ContactComponent},
    {path: 'room-metrics', component: RoomMetricsComponent}
];
