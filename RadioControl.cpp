#include "RadioControl.h"

RadioControl::RadioControl()
{}

void RadioControl::begin(void)
{
  // Initialize port PB6 as output communication pin
  DDRB |= 1UL << 6;

  // Initialize pin D7 as radio power pin
  powerPin_ = 7;
  pinMode(powerPin_, OUTPUT);
}

void RadioControl::enablePower()
{
  powerState_ = true;
  digitalWrite(powerPin_, LOW); // PMOS controlled: Enable = LOW
}
void RadioControl::disablePower()
{
  powerState_ = false;
  digitalWrite(powerPin_, HIGH); // PMOS controlled: Disable = HIGH
}
void RadioControl::togglePower()
{
  powerState_ = !powerState_;
  digitalWrite(powerPin_, powerState_ ? HIGH : LOW);
}

void RadioControl::enableCommunication()
{
  commState_ = true;
  PORTB &= ~(1UL << 6); // Inverted input
}
void RadioControl::disableCommunication()
{
  commState_ = false;
  PORTB |= 1UL << 6; // Inverted input
}
void RadioControl::toggleCommunication()
{
  commState_ = !commState_;
  PORTB ^= 1UL << 6;
}
