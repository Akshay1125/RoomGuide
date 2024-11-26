import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RoomMetricsComponent } from './room-metrics.component';

describe('RoomMetricsComponent', () => {
  let component: RoomMetricsComponent;
  let fixture: ComponentFixture<RoomMetricsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [RoomMetricsComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RoomMetricsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
