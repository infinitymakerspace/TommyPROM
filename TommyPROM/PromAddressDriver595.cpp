#include "PromAddressDriver595.h"

#define DS_PIN        A3
#define LATCH_PIN     A4
#define CLK_PIN       A5


void PromAddressDriver::begin()
{
    // The address control pins are always outputs.
    pinMode(DS_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLK_PIN, OUTPUT);
    digitalWrite(DS_PIN, LOW);
    digitalWrite(LATCH_PIN, LOW);
    digitalWrite(CLK_PIN, LOW);


    // To save time, the setAddress only writes the hi byte if it has changed.
    // The value used to detect the change is initialized to a non-zero value,
    // so set an initial address to avoid the the case where the first address
    // written is the 'magic' initial address.
    setAddress(0x0000);
}


// Set a 16 bit address in the two address shift registers.
void PromAddressDriver::setAddress(word address)
{
    byte hi = address >> 8;
    byte lo = address & 0xff;

    shiftOut(DS_PIN, CLK_PIN, MSBFIRST, hi);
    shiftOut(DS_PIN, CLK_PIN, MSBFIRST, lo);
    digitalWrite(LATCH_PIN, LOW);
    digitalWrite(LATCH_PIN, HIGH);
    digitalWrite(LATCH_PIN, LOW);
}
