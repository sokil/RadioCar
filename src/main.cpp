#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
AF_DCMotor motors[4] = {motor1, motor2, motor3, motor4};

void setup() {
  for (int m = 0; m <4; m++) {
    motors[m].setSpeed(200);
    motors[m].run(RELEASE);
  }

}

void loop() {
  uint8_t i;
  
  for (int m = 0; m < 4; m++) {
    motors[m].run(FORWARD);
  }
  
  for (i=0; i<255; i++) {
    for (int m = 0; m < 4; m++) {
      motors[m].setSpeed(i);  
    }
    
    delay(10);
  }
 
  for (i=255; i>00; i--) {
    for (int m = 0; m < 4; m++) {
      motors[m].setSpeed(i);  
    }

    delay(10);
  }

  for (int m = 0; m < 4; m++) {
    motors[m].run(BACKWARD);
  }

  for (i=0; i<255; i++) {
    for (int m = 0; m < 4; m++) {
      motors[m].setSpeed(i);  
    }

    delay(10);
  }
 
  for (i=255; i!=0; i--) {
    for (int m = 0; m < 4; m++) {
      motors[m].setSpeed(i);  
    }

    delay(10);
  }
  
  for (int m = 0; m < 4; m++) {
    motors[m].run(RELEASE);
  }
  

  delay(1000);
}