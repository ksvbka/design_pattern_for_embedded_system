#include "button_driver.h"
#include <stdio.h>
#include <stdlib.h>

void button_driver_init(button_driver_t * const me)
{
    if (me != NULL) {
        me->old_state = 0;
        me->toggle - on = 0;
        me->timer = NULL;
        me->button = NULL;
        me->microware_emitter = NULL;
    }
}
void button_driver_cleanup(button_driver_t * const me)
{

}
void button_driver_destroy(button_driver_t * const me)
{
    if (me != NULL) {
        button_driver_destroy(me);
        free(me);
    }
}

void button_driver_set_timer(button_driver_t* const me, struct timer_t* pTimer)
{
    me->timer = pTimer;
}

void button_driver_set_button(button_driver_t* const me, struct button_t* button)
{
    me->button = button;
}

void button_driver_set_controled_object(button_driver_t* const me,
                                        struct microware_emitter_t* pMicroware_emitter)
{
    me->microware_emitter = pMicroware_emitter;
}

button_driver_t* button_driver_create(struct timer_t* timer, struct microware_emitter_t* microware_emitter,
                                      struct button_t* button)
{
    button_driver_t* button_driver = (button_driver_t*)malloc(sizeof(button_driver_t));
    if (button_driver != NULL) {
        button_driver_init(button_driver);
        button_driver_set_timer(button_driver, timer);
        button_driver_set_controled_object(button_driver, microware_emitter);
        button_driver_set_button(button_driver, button);
    }
}

void button_driver_received_event(button_driver_t* const me)
{
    timer_delay(me->timer, DEBOUND_TIME);
    if (button_get_state(me->button) != me->old_state) {
        me->old_state = me->button->devices_state;
        if (!me->old_state) { // New state is off
            if (!me->toggle_on) {
                me->toggle_on = 0;
                /*...*/
                microware_emitter_stop(me->microware_emitter);
            }
        } else { // New state is on
            me->toggle_on = 1;
            microware_emitter_start(me->microware_emitter);
        }
    }
}

