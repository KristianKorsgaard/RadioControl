/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*
* by Dejan Nedelkovski, www.HowToMechatronics.com
*
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*
* Modified for iDemoLab equipment by Kristian Korsgaard
*/
#include <SPI.h>
#include <RF24.h>
#include <RadioControl.h>
#include <Led.h>
#include <printf.h>

Led led(8);
RF24 radio(5, 4); // CE, CSN
RadioControl radioC;
const byte address[6] = "00001";
const char text[] = "Hello World";

void setup() {
  radioC.begin();
  radioC.enablePower();
  radioC.enableCommunication();

  led.begin();

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  Serial.begin(9600);
  printf_begin();
  Serial.println("Ready to Transmit!");
}

void loop() {
  led.on();
  radio.write(&text, sizeof(text));
  led.off();
  delay(1000);
}
