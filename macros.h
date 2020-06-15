// Hardware configuration file.

// Clock speed
#ifndef F_CPU
#define F_CPU 16000000UL // 16MHz
#endif

// Pins
#define PWM_PIN_1              (1 << PORTD6); //PWM output pin 6

// Timers
#define COMPARE_MODE           (1 << COM0A1) // COM0A1 clear OC0A on compare match.

#define WAVEFORM_GENERATOR     (1 << WGM00) | (1 << WGM01) // Waveform generation mode 3 Fast PWM

#define TMR_OVF                (1 << TOIE0); // Timer overflow interupt enable 
//
