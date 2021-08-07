//
// Created by nikita on 07.08.2021.
//

#include "AvrControl.h"

AvrControl::AvrControl() {
    DDRC = 0b11111111; //Выходы строк
    DDRA = 0b11111111; //Входы столбцов
}


void AvrControl::display(const int8_t *points, double delay_s) {

    for(int k = 0; k < round(2000 * delay_s); k++){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                PORTC = (points[i*8+j] << (i));
                PORTA = ~(points[i*8+j] << (j));
            }
        }
        PORTC = 0b00000000;
        PORTA = 0b00000000;
        _delay_us(250);
    }

}

void AvrControl::blink13() {
    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */
    DDRB |= _BV(DDB7);

    for(int i =0; i < 64; i++) {
        /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        PORTB |= _BV(PORTB7);

        /*Wait 3000 ms */
        _delay_ms(200);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        PORTB &= ~_BV(PORTB7);

        /*Wait 3000 ms */
        _delay_ms(200);
    }

}


