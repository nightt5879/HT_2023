#ifndef __LED_H_
#define __LED_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"

void led_init(void);
void bttery_level(uint8_t led_num);

#endif
