/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
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

void setup() {
  radioC.begin();
  radioC.enableCommunication();
  radioC.enablePower();

  led.begin();

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  Serial.begin(9600);
  printf_begin();
  Serial.println("Ready to Receive!");
}

void loop() {
  if (radio.available()) {
    led.on();
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    led.off();
  }
}
