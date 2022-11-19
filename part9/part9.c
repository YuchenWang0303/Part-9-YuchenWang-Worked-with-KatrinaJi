#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "apds.h"
#include "pio_i2c.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "neopixel.h"


const int address = 0x39;

#define SDA 22
#define SCL 23
#define WS2812_PIN 11

uint32_t rgb_to_neopixel(uint8_t r, uint8_t g, uint8_t b){
    uint32_t result = 0;
    result |= (uint32_t)r << 16u;
    result |= (uint32_t)g << 8u;
    result |= (uint32_t)b;
    return result;
}

int main(){
    stdio_init_all();
    while(stdio_usb_connected()!=true);
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio,&i2c_program);
    i2c_program_init(pio, sm, offset, SDA, SCL);
    init_sensor();
    neopixel_init();
    
    while(true){
        int32_t c;
        int32_t r;
        int32_t g;
        int32_t b;
        int32_t proximity;
        proximity_sensor(&proximity, pio, sm, address, true);
        read_rgbc(&r, &g, &b, &c);
        printf("proximity: %d", proximity);
        printf("\nr:%d, g:%d, b:%d, c:%d\n", r, g, b, c);
        neopixel_set_rgb(rgb_to_neopixel( r, g, b));
        sleep_ms(50);
    }
    
    return 0;
}