/*
 * FreeRTOS configuration for LAUNCHXL2-RM46.
 * This is (almost) automatically generated with HalCoGen.
 *
 * Created: 2017-04-17
 * Author:  Heikki Salokanto <heikki@reaktorspace.com>
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION		  1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1
#define configUSE_FPU							1
#define configUSE_IDLE_HOOK			  0
#define configUSE_TICK_HOOK			  0
#define configUSE_TRACE_FACILITY	  0
#define configUSE_16_BIT_TICKS		  0
#define configCPU_CLOCK_HZ			  ( ( unsigned portLONG ) 55000000 ) /* Timer clock. */
#define configTICK_RATE_HZ			  ( ( TickType_t ) 250 )
#define configMAX_PRIORITIES		  ( 5 )
#define configMINIMAL_STACK_SIZE	  ( ( unsigned portSHORT ) 128 )
#define configTOTAL_HEAP_SIZE		  ( ( size_t ) 32768 )
#define configMAX_TASK_NAME_LEN		  ( 16 )
#define configIDLE_SHOULD_YIELD		  1
#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_MALLOC_FAILED_HOOK  1


/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		    0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Mutexes */
#define configUSE_MUTEXES               1
#define configUSE_RECURSIVE_MUTEXES     1

/* Semaphores */
#define configUSE_COUNTING_SEMAPHORES   1

/* Timers */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY		( 3 )
#define configTIMER_QUEUE_LENGTH		10
#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE )

/* Set the following definitions to 1 to include the API function, or zero to exclude the API function. */
#define INCLUDE_vTaskPrioritySet		    1
#define INCLUDE_uxTaskPriorityGet		    1
#define INCLUDE_vTaskDelete					1
#define INCLUDE_vTaskCleanUpResources	    0
#define INCLUDE_vTaskSuspend		     	1
#define INCLUDE_xTaskResumeFromISR			1
#define INCLUDE_vTaskDelayUntil			    1
#define INCLUDE_vTaskDelay				    1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_uxTaskGetStackHighWaterMark 1


/* debug ASSERT */
#define configASSERT( x ) if( ( x ) == pdFALSE ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#endif /* FREERTOS_CONFIG_H */
