/*
 * A FreeRTOS task that toggles on-board LEDs.
 *
 * Created: 2017-04-14
 * Author:  Heikki Salokanto <heikki@reaktorspace.com>
 */

#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "os_portmacro.h"
#include "os_task.h"
#include "led_control.h"


#define LED_TASK_PRIORITY       (tskIDLE_PRIORITY + 1)
#define LED_TASK_STACK_SIZE     (1024 / sizeof(int))
#define LED_RATE_MS             500UL

/* Prototypes */
static void blink_leds(void *pvParameters);


void start_blink_task(void)
{
    led_init();
    xTaskCreate(blink_leds, "LEDx", LED_TASK_STACK_SIZE, NULL, LED_TASK_PRIORITY, NULL);
}


/* A FreeRTOS task to toggle the LEDs in sequence.
 */
static void blink_leds(void *pvParameters)
{
    unsigned int led_num = 0;
    const unsigned int leds = led_count();
    led_set(0, true);

    const TickType_t rate_ticks = LED_RATE_MS / portTICK_PERIOD_MS;
    TickType_t last_flash_time = xTaskGetTickCount();

	for (;;)
	{
	    vTaskDelayUntil(&last_flash_time, rate_ticks);

        led_toggle(led_num);
        if (++led_num >= leds)
            led_num = 0;
        led_toggle(led_num);
	}
}
