/*
 * led_control.h
 *
 * Created: 2017-04-14
 * Author:  Heikki Salokanto <heikki@reaktorspace.com>
 */

#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <stdbool.h>


/**
 * Initialize IO ports. Need to be called first.
 */
void led_init(void);

/**
 * Get number of leds available on board.
 */
unsigned int led_count(void);

/**
 * Turn a LED on or off.
 *
 * @param  led_num   number of the led, 0 <= led_num < LED_COUNT
 * @param  onoff     true to light the LED, false to turn it off
 */
void led_set(unsigned int led_num, bool onoff);

/**
 * Toggle a LED -- if it's on, turn it off, and vice versa.
 *
 * @param  led_num   number of the led, 0 ≤ led_num < LED_COUNT
 */
void led_toggle(unsigned int led_num);

/**
 * Turn all the LEDs off.
 */
void led_off_all(void);


#endif // LED_CONTROL_H
