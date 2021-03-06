// Hardware configuration file.

// Clock speed
#ifndef F_CPU
#define F_CPU 16000000UL // 16MHz
#endif

// Pins
#define PWM_PIN_1              (1 << PORTD6) //PWM output pin 6
#define LED_PIN_1              (1 << PORTD4) //LED pin 4
#define BUTTON_PIN_1           (1 << PORTB0) //Button pin

// Timers
#define COMPARE_MODE           (1 << COM0A1) // COM0A1 clear OC0A on compare match.

#define WAVEFORM_GENERATOR     (1 << WGM00) | (1 << WGM01) // Waveform generation mode 3 Fast PWM

#define TMR_OVF                (1 << TOIE0) // Timer overflow interupt enable 
// Pin change interrupts
#define PIN_CHANGE             (1 << PCINT0) //Enable the pin change interrupt for PB0.
