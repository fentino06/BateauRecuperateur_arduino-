#include <VirtualWire_Config.h>
#include <VirtualWire.h>

#define LED 2
#define JOYSTICK_X 0
#define JOYSTICK_Y 1
#define EMITTER 10

const byte MESSAGE_SIZE = 9;
const long MESSAGE_DELAY = 30;

void setup() {
  //Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);

  digitalWrite(LED, HIGH);
  
  vw_set_tx_pin(EMITTER);
  vw_setup(2000);
}

void loop() {
  byte plain[MESSAGE_SIZE];
  String message = toString(analogRead(JOYSTICK_X)) + toString(1023-analogRead(JOYSTICK_Y));
  message.getBytes(plain, MESSAGE_SIZE);
  vw_send(plain, MESSAGE_SIZE);
  vw_wait_tx();
  //Serial.println("Message sent : " + message);
  delay(MESSAGE_DELAY);
}


String toString(int value) {
  String result = "";
  for (int i = 0; i < 3 - int(log10(value)); i++) {
    result += "0";
  }
  return result + String(value);
}
