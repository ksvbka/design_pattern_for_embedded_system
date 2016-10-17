#ifndef __BUTTON_DRIVER_H__
#define __BUTTON_DRIVER_H__

#define DEBOUND_TIME (100)

struct button_t; /*Simutate a hardware button*/
struct microware_emitter_t; /*An object controled by button*/
struct timer_t; /*Timer to debound*/

typedef button_driver{
    char old_state;
    char toggle_on;
    struct timer_t* timer;
    struct button_t* button;
    struct microware_emitter_t* microware_emitter;
} button_driver_t;

void button_driver_init(button_driver_t * const me);
void button_driver_cleanup(button_driver_t * const me);
void button_driver_destroy(button_driver_t * const me);
button_driver_t* button_driver_create(struct timer_t* timer,
                                      struct microware_emitter_t* microware_emitter,
                                      struct button_t* button);

/* Function will active when receipt an event from button hardware, usually implement by interrupt*/
void button_driver_received_event(button_driver_t* const me);
void button_driver_set_timer(button_driver_t* const me, struct timer_t* pTimer);
void button_driver_set_controled_object(button_driver_t* const me,
                                        struct microware_emitter_t* microware_emitter);
void button_driver_set_button(button_driver_t* const me, struct button_t* button);
#endif
