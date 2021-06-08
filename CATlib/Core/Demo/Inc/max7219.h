/*
 * max7219.h
 *
 *  Created on: 30.04.2016
 *      Author: harry
 */

#ifndef MAX7219_H_
#define MAX7219_H_

void init_max7219(void);
void set_brightness_max7219(uint8_t brightness);
void set_digit_max7219(uint8_t digit, uint8_t val);
void set_val_max7219(int32_t val, uint8_t dpoint);


#endif /* MAX7219_H_ */
