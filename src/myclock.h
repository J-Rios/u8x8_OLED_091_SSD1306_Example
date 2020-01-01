/**************************************************************************************************/
// File: myclock.h
// Description: Simple Clock behaviour implementation
// Created on: 31 dec. 2019
// Last modified date: 31 dec. 2019
// Version: 1.0.0
/**************************************************************************************************/

/* Include Guard */

#ifndef MYCLOCK_H_
#define MYCLOCK_H_

/**************************************************************************************************/

/* Libraries */

#include <stdbool.h>
#include <stdint.h>

/**************************************************************************************************/

class MyClock
{
    public:
        MyClock(void);
        bool set_time(const uint8_t h, const uint8_t m, const uint8_t s);
        void increase_time(void);
        uint8_t get_s(void);
        uint8_t get_m(void);
        uint8_t get_h(void);
        bool get_str_s(char* cstr_s, const uint8_t cstr_s_size);
        bool get_str_m(char* cstr_m, const uint8_t cstr_m_size);
        bool get_str_h(char* cstr_h, const uint8_t cstr_h_size);
        bool get_str_time(char* cstr_time, const uint8_t cstr_time_size);

    private:
        uint8_t _s, _m, _h;
        char _cstr_s[3];
        char _cstr_m[3];
        char _cstr_h[3];
};

/**************************************************************************************************/

#endif
