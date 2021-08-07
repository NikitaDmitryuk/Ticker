//
// Created by nikita on 07.08.2021.
//

#ifndef SNAKEAVR_AVRCONTROL_H
#define SNAKEAVR_AVRCONTROL_H

#include <avr/io.h>
#include <util/delay.h>

class AvrControl {
public:
    AvrControl();
    void display(const int8_t points[64], double delay_s);
    void blink13();

};


#endif //SNAKEAVR_AVRCONTROL_H
