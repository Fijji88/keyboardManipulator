// Functions declarations.

#include <avr/io.h>
#include "macros.h"
#include "functions.h"
int HWconfig()
{
    DDRD = PWM_PIN_1 | LED_PIN_1;
    PORTD &= ~LED_PIN_1; // Set output pin to low.
    TCCR0A = COMPARE_MODE | WAVEFORM_GENERATOR;
    TIMSK0 = TMR_OVF;
    return 1;
};

void updateDC(double dutycycle)
{
    OCR0A = (dutycycle/100)*255;
};

void startTC(int prescalar)
{
    TCCR0B = (1 << prescalar);
};

void toggleLED()
{
    PIND = LED_PIN_1;

};
