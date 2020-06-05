#ifndef __IOXHOP_PAJ7620_CPP__
#define __IOXHOP_PAJ7620_CPP__

#include "IOXhop_PAJ7620.h"

IOXhop_PAJ7620::IOXhop_PAJ7620() {
  
}

bool IOXhop_PAJ7620::begin() {
  Wire.beginTransmission(PAJ7620_ADDR);
  Wire.write(0xEF);
  Wire.write(0x01);
  int error = Wire.endTransmission();

  if (error != 0) {
    IOXHOP_PAJ7620_DEBUG("Switch to bank 1 fail");
    return false;
  }

  Wire.beginTransmission(PAJ7620_ADDR);
  Wire.write(0x72);
  Wire.write(0x01);
  error = Wire.endTransmission();

  if (error != 0) {
    IOXHOP_PAJ7620_DEBUG("Config Enable/Disable register fail");
    return false;
  }

  Wire.beginTransmission(PAJ7620_ADDR);
  Wire.write(0xEF);
  Wire.write(0x00);
  error = Wire.endTransmission();

  if (error != 0) {
    IOXHOP_PAJ7620_DEBUG("Switch to bank 0 fail");
    return false;
  }
}

int IOXhop_PAJ7620::getGesture() {
  Wire.beginTransmission(PAJ7620_ADDR);
  Wire.write(0x43);
  int error = Wire.endTransmission();

  if (error != 0) {
    IOXHOP_PAJ7620_DEBUG("Write offset register to 0x43 fail");
    return -1;
  }

  Wire.requestFrom(PAJ7620_ADDR, 2);

  if (Wire.available() < 2) {
    IOXHOP_PAJ7620_DEBUG("Read register 0x43 fail");
    return -1;
  }

  int data = 0;
  data = Wire.read();
  data |= Wire.read() << 8;

  return data;
}

IOXhop_PAJ7620 PAJ7620;

#endif
