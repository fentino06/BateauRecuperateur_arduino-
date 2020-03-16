#include <VirtualWire_Config.h>
#include <VirtualWire.h>
#include <ServoTimer2.h>

#define LEFT_MOTOR 5
#define RIGHT_MOTOR 6
#define RECEIVER 11

#define MIN_MOTOR_VALUE 1000
#define MAX_MOTOR_VALUE 2000

const byte MESSAGE_SIZE = 8;
const long UPDATE_DELAY = 30;
const int ERROR_RANGE = round(float(MAX_MOTOR_VALUE - MIN_MOTOR_VALUE) / 25.0);

ServoTimer2 leftMotor, rightMotor;

void setup() {
  //Serial.begin(9600);

  leftMotor.attach(LEFT_MOTOR);
  rightMotor.attach(RIGHT_MOTOR);

  initMotors();
  
  vw_set_rx_pin(RECEIVER);
  vw_setup(2000);
  vw_rx_start();
}


void loop() {
  byte plain[MESSAGE_SIZE];
  
  vw_wait_rx();

  if (vw_get_message(plain, &MESSAGE_SIZE)) {
    String message = String((char*)plain);
    int x = mapValue(message.substring(0, 4).toInt()),
        y = mapValue(message.substring(4, 8).toInt());
    //Serial.println("Received :   X = " + String(x) + "   Y = " + String(y));
    updateMotors(x, y);
    delay(UPDATE_DELAY);
  }
}

int mapValue(int value) {
  int result = map(value, 0, 1023, (2*MIN_MOTOR_VALUE) - MAX_MOTOR_VALUE, MAX_MOTOR_VALUE);
  
  if (result < MIN_MOTOR_VALUE+ERROR_RANGE and result > MIN_MOTOR_VALUE-ERROR_RANGE) {
    return MIN_MOTOR_VALUE;
  }
  
  return result;
}

void updateMotors(int x, int y) {
  int left = -1, right = -1;
  if (y <= MIN_MOTOR_VALUE) {
    left = 1000;
    right = 1000;
  } else {
    int xValue = int(float(MAX_MOTOR_VALUE - MIN_MOTOR_VALUE - abs(x - MIN_MOTOR_VALUE)) * float(y-MIN_MOTOR_VALUE) / float(MAX_MOTOR_VALUE-MIN_MOTOR_VALUE)) + MIN_MOTOR_VALUE;
    if (x < MIN_MOTOR_VALUE) {
      right = y;
      left = xValue;
    } else {
      left = y;
      right = xValue;
    }
  }
  leftMotor.write(left);
  rightMotor.write(right);
  //Serial.println("LEFT = " + String(left) + "   RIGHT = " + String(right));
}

void initMotors() {
  //Serial.println("Initializing...");
  leftMotor.write(2000);
  rightMotor.write(2000);
  delay(1000);
  leftMotor.write(1000);
  rightMotor.write(1000);
  delay(8000);
  //Serial.println("Initialized.");
}
