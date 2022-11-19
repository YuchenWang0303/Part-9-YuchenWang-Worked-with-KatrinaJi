# Part 9 YuchenWang Worked with KatrinaJi, Ryan Zhang

---
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2b

### Teammate: Yuchen Wang, Katrina Ji

    Yuchen Wang
    wangyuchen0303@gmail.com
    Tested on:  MacBook Pro (14-inch, 2021), macOS Monterey 12.6
    
    Katrina Ji
    katji@seas.upenn.edu
    Tested on:  MacBook Pro (14-inch, 2021), macOS Monterey 12.6

---

# GIF of Results:

![IMG_9823](https://user-images.githubusercontent.com/105755054/202834649-bc8613e9-938f-4907-99f3-8f5073d41c6b.GIF)

# Circuit Diagram:

![IMG_9824 Small](https://user-images.githubusercontent.com/105755054/202834687-a750a89a-762c-4e21-876c-d2148004600b.jpeg)

# Screenshot of I2C Traffic:

<img width="1145" alt="Screen Shot 2022-11-18 at 23 41 51" src="https://user-images.githubusercontent.com/105755054/202834716-c41cc988-e840-4f1a-acb1-d7aaf688454e.png">

---
# Note:
  when I try to run this code after slightly modified, I find I can not read the data from sensor continiously. It is beacuse of the same PIO and offset variable. Hence, we have to use PIO0 for APDS9960 and PIO1 for ws2812. Then it can work correct.
  
---
# Modified Part:
- Since I already make the ```adps.h```, I only need to convert the R G B to a 32bits length value to ```nioixel_rgb()``` function.
- In this part I adopt the converting code from TomGoh
```
uint32_t rgb_to_neopixel(uint8_t r, uint8_t g, uint8_t b){
    uint32_t result = 0;
    result |= (uint32_t)r << 16u;
    result |= (uint32_t)g << 8u;
    result |= (uint32_t)b;
    return result;
}
```

