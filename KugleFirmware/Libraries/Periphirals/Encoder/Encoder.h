/* Copyright (C) 2018 Thomas Jespersen, TKJ Electronics. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 *
 * Contact information
 * ------------------------------------------
 * Thomas Jespersen, TKJ Electronics
 * Web      :  http://www.tkjelectronics.com
 * e-mail   :  thomasj@tkjelectronics.com
 * ------------------------------------------
 */
 
#ifndef PERIPHIRALS_ENCODER_H
#define PERIPHIRALS_ENCODER_H

#include "stm32h7xx_hal.h"

class Encoder
{
	public:
		typedef enum timer_t {
			TIMER_UNDEFINED = 0,
			TIMER2,
			TIMER3,
			TIMER4
		} timer_t;

	public:
		Encoder(timer_t timer);
		~Encoder();

		void ConfigureEncoderGPIO();
		void ConfigureEncoderPeripheral();

		int32_t Get();

	public:
		typedef struct hardware_resource_t {
			timer_t timer;
			TIM_HandleTypeDef handle;
			int32_t offsetValue;
		} hardware_resource_t;

		static hardware_resource_t * resTIMER2;
		static hardware_resource_t * resTIMER3;
		static hardware_resource_t * resTIMER4;
	
	private:
		hardware_resource_t * _hRes;

	public:
		static void InterruptHandler(Encoder::hardware_resource_t * encoder);
};
	
	
#endif
