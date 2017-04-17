/*
 * led_control.c
 *
 * Created: 2017-04-14
 * Author:  Heikki Salokanto <heikki@reaktorspace.com>
 */

#include "gio.h"
#include "led_control.h"

const uint32_t LED_BITS[] = { 0x01, 0x02 };
const unsigned int LED_COUNT = sizeof(LED_BITS) / sizeof(uint32_t);

/* Status of the led array */
static volatile uint32_t leds_status = 0;


unsigned int led_count(void)
{
    return LED_COUNT;
}

void led_init(void)
{
    /* Initialize the IO ports that drive the LEDs */
    gioSetDirection(gioPORTB, 0xFFFFFFFF);
    led_off_all();
}

void led_off_all(void)
{
    leds_status = 0;
    for (unsigned int i = 0; i < LED_COUNT; i++)
        gioSetBit(gioPORTB, LED_BITS[i], 0);
}

void led_set(unsigned int led_num, bool onoff)
{
    if (led_num >= LED_COUNT)
        return;

    unsigned int bit = (1 << led_num);

    if (onoff)
        leds_status |= bit;
    else
        leds_status &= ~bit;

    gioSetBit(gioPORTB, LED_BITS[led_num], onoff);
}

void led_toggle(unsigned int led_num)
{
    if (led_num >= LED_COUNT)
        return;

    unsigned int bit = (1 << led_num);
    led_set(led_num, (leds_status & bit) ^ bit);
}
