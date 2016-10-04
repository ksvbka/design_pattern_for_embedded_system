/*
    Motor interface:
    Bits reflect ourrent settings for reading and writing.
    Write 0 to clear a bit, 1 to set a bit.
    Width: 16 bits
    Bit Range       Name            Description
    0               Motor on /off   0 - off, 1 - on
    1-2             Direction       0 - off, 10 - forward, 01 - reverse
    3-7             speed           00000 (0d) stopped, 11111 (31d) max speed
    8               Error status    0 = no error, 1 = error
    9 - 15          Error code      00001 = no power to motor
                                    00010 = no torque
                                    000100 = BIT failure
                                    0001000 = over temperature fault
                                    0xx0000 = reserved bits
                                    1000000 = unknown error
*/

#ifndef __MOTO_DATA_H
#define __MOTO_DATA_H

typedef enum direction_type_t direction_type_t;
enum direction_type_t {
    ERROR = 0,
    STOP,
    FORWARD,
    REVERSE
};

typedef union motor_data_t motor_data_t;
union motor_data_t {
    struct {
        unsigned char on_off : 1;
        direction_type_t direction :2;
        unsigned int speed : 7;

        /*Error detect*/
        unsigned char error_status : 1;

        unsigned char error_no_power : 1;
        unsigned char error_no_torque : 1;
        unsigned char error_bit_false : 1;
        unsigned char error_over_temperator : 1;
        unsigned char error_reverse_1 : 1;
        unsigned char error_reverse_2 : 1;
    } bit;

    unsigned int reg;
};


#endif //__MOTO_DATA_H
