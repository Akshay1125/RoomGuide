// import { Injectable } from '@angular/core';
// import * as data from '../../assets/data.json'; // Adjust the path as needed

// @Injectable({
//   providedIn: 'root'
// })
// export class FreeRoomService {

//   constructor() { }

//   getFreeRooms(day: string, timeIndex: number): Promise<any> {
//     // Use the imported JSON data directly
//     return new Promise((resolve, reject) => {
//       try {
//         const roomData = (data as any)[day][timeIndex];
//         resolve(roomData);
//       } catch (error) {
//         console.error('Error accessing data:', error);
//         reject(error);
//       }
//     });
//   }
// }
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class FreeRoomService {

  constructor() { }

  getFreeRooms(day: string, timeIndex: number): Promise<any> {
    const url = '../assets/db.json';
    // instead of url use data.json from data_scrapping folder

    // const url = 'data.json';

    return fetch(url)
      .then(response => response.json())
      .then(data => {
        return data[day][timeIndex]; // Adjust this to match the structure of your JSON
      })
      .catch(error => {
        console.error('Error fetching data:', error);
        throw error;
      });
  }
}

