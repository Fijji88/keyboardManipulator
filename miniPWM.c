// Keyboard manipulator code

#include "macros.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "functions.h"



static double dutycycle = 0;
static int toggle = 0;
static int heartbeat = 0;

int main(void)
{
    while(HWconfig() != 1)

    updateDC(dutycycle);

    sei();

    startTC(CS00);

    while(1)
    {
        _delay_us(10); 
        if(heartbeat)
        {
            dutycycle -= 1;

            if(dutycycle < 1)
            {
                heartbeat = 0;
            }

        }
        else
        {
            dutycycle += 1;

            if(dutycycle > 99)
            {
                heartbeat = 1;
            }
        }

        if(toggle == 1)
        {
            toggleLED();
            toggle = 0;
        }
    }

}

ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutycycle/100)*255;
}

ISR(PCINT0_vect)
{
    toggle = 1;
}
