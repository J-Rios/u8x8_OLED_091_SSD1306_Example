#include "myclock.h"


MyClock::MyClock(void)
{
    _s = 0; _m = 0; _h = 0;
    _cstr_s[0] = '0'; _cstr_s[1] = '0'; _cstr_s[2] = '\0';
    _cstr_m[0] = '0'; _cstr_m[1] = '0'; _cstr_m[2] = '\0';
    _cstr_h[0] = '0'; _cstr_h[1] = '0'; _cstr_h[2] = '\0';
}

bool MyClock::set_time(const uint8_t h, const uint8_t m, const uint8_t s)
{
    uint8_t s0, s1, m0, m1, h0, h1;

    if(h > 23)
        return false;
    if(m > 59)
        return false;
    if(s > 59)
        return false;

    _h = h;
    _m = m;
    _s = s;

    if(_h < 10)
    {
        _cstr_h[0] = '0';
        _cstr_h[1] = _h + '0';
    }
    else
    {
        h0 = 0;
        h1 = _h;
        while(h1 >= 10)
        {
            h0 = h0 + 1;
            h1 = h1 - 10;
        }
        _cstr_h[0] = h0 + '0';
        _cstr_h[1] = h1 + '0';
    }

    if(_m < 10)
    {
        _cstr_m[0] = '0';
        _cstr_m[1] = _m + '0';
    }
    else
    {
        m0 = 0;
        m1 = _m;
        while(m1 >= 10)
        {
            m0 = m0 + 1;
            m1 = m1 - 10;
        }
        _cstr_m[0] = m0 + '0';
        _cstr_m[1] = m1 + '0';
    }

    if(_s < 10)
    {
        _cstr_s[0] = '0';
        _cstr_s[1] = _s + '0';
    }
    else
    {
        s0 = 0;
        s1 = _s;
        while(s1 >= 10)
        {
            s0 = s0 + 1;
            s1 = s1 - 10;
        }
        _cstr_s[0] = s0 + '0';
        _cstr_s[1] = s1 + '0';
    }

    return true;
}

void MyClock::increase_time(void)
{
    uint8_t s0, s1, m0, m1, h0, h1;

    _s = _s + 1;
    if(_s == 60)
    {
        _s = 0;
        _m = _m + 1;
        if(_m == 60)
        {
            _m = 0;
            _h = _h + 1;
            if(_h == 24)
                _h = 0;

            if(_h < 10)
            {
                _cstr_h[0] = '0';
                _cstr_h[1] = _h + '0';
            }
            else
            {
                h0 = 0;
                h1 = _h;
                while(h1 >= 10)
                {
                    h0 = h0 + 1;
                    h1 = h1 - 10;
                }
                _cstr_h[0] = h0 + '0';
                _cstr_h[1] = h1 + '0';
            }
        }

        if(_m < 10)
        {
            _cstr_m[0] = '0';
            _cstr_m[1] = _m + '0';
        }
        else
        {
            m0 = 0;
            m1 = _m;
            while(m1 >= 10)
            {
                m0 = m0 + 1;
                m1 = m1 - 10;
            }
            _cstr_m[0] = m0 + '0';
            _cstr_m[1] = m1 + '0';
        }
    }

    if(_s < 10)
    {
        _cstr_s[0] = '0';
        _cstr_s[1] = _s + '0';
    }
    else
    {
        s0 = 0;
        s1 = _s;
        while(s1 >= 10)
        {
            s0 = s0 + 1;
            s1 = s1 - 10;
        }
        _cstr_s[0] = s0 + '0';
        _cstr_s[1] = s1 + '0';
    }
}

uint8_t MyClock::get_s(void)
{
    return _s;
}

uint8_t MyClock::get_m(void)
{
    return _m;
}

uint8_t MyClock::get_h(void)
{
    return _h;
}

bool MyClock::get_str_s(char* cstr_s, const uint8_t cstr_s_size)
{
    if(cstr_s_size < 3)
        return false;

    cstr_s[0] = _cstr_s[0];
    cstr_s[1] = _cstr_s[1];
    cstr_s[2] = '\0';

    return true;
}

bool MyClock::get_str_m(char* cstr_m, const uint8_t cstr_m_size)
{
    if(cstr_m_size < 3)
        return false;

    cstr_m[0] = _cstr_m[0];
    cstr_m[1] = _cstr_m[1];
    cstr_m[2] = '\0';

    return true;
}

bool MyClock::get_str_h(char* cstr_h, const uint8_t cstr_h_size)
{
    if(cstr_h_size < 3)
        return false;

    cstr_h[0] = _cstr_h[0];
    cstr_h[1] = _cstr_h[1];
    cstr_h[2] = '\0';

    return true;
}

bool MyClock::get_str_time(char* cstr_time, const uint8_t cstr_time_size)
{
    if(cstr_time_size < 9)
        return false;

    cstr_time[0] = _cstr_h[0];
    cstr_time[1] = _cstr_h[1];
    cstr_time[2] = ':';
    cstr_time[3] = _cstr_m[0];
    cstr_time[4] = _cstr_m[1];
    cstr_time[5] = ':';
    cstr_time[6] = _cstr_s[0];
    cstr_time[7] = _cstr_s[1];
    cstr_time[8] = '\0';

    return true;
}
