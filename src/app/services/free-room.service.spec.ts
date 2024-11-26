import { TestBed } from '@angular/core/testing';

import { FreeRoomService } from './free-room.service';

describe('FreeRoomService', () => {
  let service: FreeRoomService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(FreeRoomService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
