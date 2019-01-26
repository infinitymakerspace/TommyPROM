#ifndef INCLUDE_PROM_ADDRESS_DRIVER_595_H
#define INCLUDE_PROM_ADDRESS_DRIVER_595_H

#include "Arduino.h"

class PromAddressDriver {
  public:
    static void begin();
    static void setAddress(word address);
};


#endif // #define INCLUDE_PROM_ADDRESS_DRIVER_595_H
