#ifndef __IOXHOP_PAJ7620_H__
#define __IOXHOP_PAJ7620_H__

#include <Arduino.h>
#include <Wire.h>

#define IOXHOP_PAJ7620_DEBUG(a) Serial.println(a)
// #define IOXHOP_PAJ7620_DEBUG(a) ;

#define PAJ7620_ADDR 0x73

#define GESTURE_WAVE              (1<<8)
#define GESTURE_COUNTER_CLOCKWISE (1<<7)
#define GESTURE_CLOCKWISE         (1<<6)
#define GESTURE_BACKWORD          (1<<5)
#define GESTURE_FORWARD           (1<<4)
#define GESTURE_RIGHT             (1<<3)
#define GESTURE_LEFT              (1<<2)
#define GESTURE_DOWN              (1<<1)
#define GESTURE_UP                (1<<0)

class IOXhop_PAJ7620 {

  public:
   IOXhop_PAJ7620();

   bool begin();
   int getGesture() ;
   
}
;

extern IOXhop_PAJ7620 PAJ7620;

#endif
