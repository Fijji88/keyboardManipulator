#ifndef F_CPU
#define F_CPU 16000000UL //16MHz clock speed
#endif


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

double dutycycle = 0;

int main(void)
{
    DDRD = (1 << PORTD6); //Set pin 13/ PB1 as Output

    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01); //Waveform generator set to fast pwm or mode 3.

    TIMSK0 = (1 << TOIE0); //Time mask

    OCR0A = (dutycycle/100)*255;

    sei();

    TCCR0B = (1 << CS00); //Prescalar

    while(1)
    {
        _delay_ms(100);

        dutycycle += 10;

        if(dutycycle > 100)
        {
            dutycycle =0;
        }
    }

}

ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutycycle/100)*255;
}
