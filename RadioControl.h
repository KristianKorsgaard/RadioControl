#ifndef RADIOCONTROL_H
#define RADIOCONTROL_H

#include "Arduino.h"

class RadioControl
{
public:
  RadioControl();

  void begin(void);

  void enablePower();
  void disablePower();
  void togglePower();

  void enableCommunication();
  void disableCommunication();
  void toggleCommunication();
private:
  bool powerState_, commState_;
  byte powerPin_;
};

#endif /* end of include guard: RADIOCONTROL_H */
