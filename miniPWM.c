// Keyboard manipulator code

#include "macros.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "functions.h"



static double dutycycle = 0;


int main(void)
{
    while(HWconfig() != 1)

    updateDC(dutycycle);

    sei();

    startTC(CS00);

    while(1)
    {
        _delay_us(1); 
        dutycycle += 1;

        if(dutycycle > 100)
        {
            dutycycle = 0;
            toggleLED();
        }
    }

}

ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutycycle/100)*255;
}
