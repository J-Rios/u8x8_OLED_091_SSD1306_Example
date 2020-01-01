#include <Arduino.h>
#include <U8x8lib.h>
#include "myclock.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

//U8X8_SSD1306_128X32_UNIVISION_SW_I2C u8x8(/*clock=*/21, /*data=*/20, /*reset=*/U8X8_PIN_NONE);
U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/*reset=*/U8X8_PIN_NONE, /*clock=*/SCL, /*data=*/SDA);
MyClock myclock;


void setup(void)
{
    u8x8.begin();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setPowerSave(0);
    u8x8.clearDisplay();
    u8x8.drawString(0, 0, "   OLED Clock   ");
    u8x8.drawString(0, 1, "----------------");
    myclock.set_time(14, 30, 0);
}

void loop(void)
{
    static uint32_t t0 = millis();
    char cstr_time[9];
    char text[16];

    if(millis()-t0 >= 1000)
    {
        myclock.get_str_time(cstr_time, 9);
        myclock.increase_time();

        snprintf(text, 16, "    %s", cstr_time);
        u8x8.drawString(0, 3, text);

        t0 = millis();
    }

    delay(100);
}
