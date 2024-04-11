#ifndef SSD_HPP
#define SSD_HPP

#include "pico/stdlib.h"

extern const uint LED_PINS[];
extern const bool SEGMENT_MAP[10][7];

class UpDownCounter {
public:
    UpDownCounter(const uint ledPins[8]);

    void countUp();

    void countDown();
    
    void displayDigit(int digit);
};

#endif // SSD_HPP