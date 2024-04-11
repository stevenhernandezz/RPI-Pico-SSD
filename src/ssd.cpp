#include "pico/stdlib.h"
#include "ssd.hpp"
#include <iostream>

const uint LED_PINS[] = {2, 3, 4, 5, 6, 7, 8};

const bool SEGMENT_MAP[10][7] = {
    //A  B  C  D  E  F  G
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

UpDownCounter::UpDownCounter(const uint ledPins[8]) {
    for (int i = 0; i < 8; ++i) {
        gpio_init(ledPins[i]);
        gpio_set_dir(ledPins[i], GPIO_OUT);
    }
}

void UpDownCounter::countUp() {
    for (int i = 0; i <= 9; i++) {
        std::cout << "Counting Up: " << i << std::endl;             
        displayDigit(i);
        sleep_ms(750);
    }
}

void UpDownCounter::countDown() {
    for (int i = 9; i >= 0; i--) {
        std::cout << "Counting Down: " << i << std::endl;
        displayDigit(i);
        sleep_ms(750);
    }
}

void UpDownCounter::displayDigit(int digit) {
    // valid range
    if (digit < 0 || digit > 9) {
        return;
    }

    // Display the digit 
    for (int i = 0; i < 7; ++i) {
        gpio_put(LED_PINS[i], !SEGMENT_MAP[digit][i]);
    }
}