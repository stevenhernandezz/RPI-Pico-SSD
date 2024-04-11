#include "pico/stdlib.h"
#include "ssd.hpp"

int main() {
    const int switchPin = 9; 
    const uint ledPins[] = {2, 3, 4, 5, 6, 7, 8}; 
    UpDownCounter counter(ledPins);

    gpio_init(switchPin);
    gpio_set_dir(switchPin, GPIO_IN);

    int state = 0;
    while (true) {
        if (!gpio_get(switchPin)) {
            if (state == 0) {
                counter.countUp();
                state = 1;
            } else {
                counter.countDown();
                state = 0;
            }
        }
        sleep_ms(100); 
    }
    return 0;
}