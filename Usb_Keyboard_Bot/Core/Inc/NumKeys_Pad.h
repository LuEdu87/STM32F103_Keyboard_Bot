/*
 * NumKeys_Pad.h
 *
 *  Created on: 2 jul. 2020
 *      Author: Edu
 */

#ifndef NUMKEYS_PAD_H_
#define NUMKEYS_PAD_H_

/*-------------------------------------------------------------------------------------------------------
 * INCLUDES
 --------------------------------------------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"


/*-------------------------------------------------------------------------------------------------------
 * DEFINES
 --------------------------------------------------------------------------------------------------------*/


 /* Matching the PadNumber and the ASCII code*/

#define		Pressed_0		0x30
#define		Pressed_1 		0x31
#define		Pressed_2 		0x32
#define		Pressed_3 		0x33
#define		Pressed_4 		0x34
#define		Pressed_5 		0x35
#define		Pressed_6 		0x36
#define		Pressed_7 		0x37
#define		Pressed_8 		0x38
#define		Pressed_9 		0x39
#define		Pressed_A		0x41
#define		Pressed_B		0x42
#define		Pressed_C		0x43
#define		Pressed_D		0x44
#define		Pressed_Aste	0x2A
#define		Pressed_HashT	0x23






/*Definition of physical pins with Ucontroller Pins
 * NOTE: If you want to use others pins, just change this "#define" with the port and the number of each pin.
 * */

#define		Pin_1_Letter		GPIOA
#define		Pin_1_Number		GPIO_PIN_0

#define		Pin_2_Letter		GPIOA
#define		Pin_2_Number		GPIO_PIN_1

#define		Pin_3_Letter		GPIOA
#define		Pin_3_Number		GPIO_PIN_2

#define		Pin_4_Letter		GPIOA
#define		Pin_4_Number		GPIO_PIN_3

#define		Pin_5_Letter		GPIOA
#define		Pin_5_Number		GPIO_PIN_4

#define		Pin_6_Letter		GPIOA
#define		Pin_6_Number		GPIO_PIN_5

#define		Pin_7_Letter		GPIOA
#define		Pin_7_Number		GPIO_PIN_6

#define		Pin_8_Letter		GPIOA
#define		Pin_8_Number		GPIO_PIN_7


/*Size of Matrix*/

#define		Row_Size		4
#define		Column_Size		4


/*-------------------------------------------------------------------------------------------------------
 * STRUCTS
 --------------------------------------------------------------------------------------------------------*/

typedef struct
{
	GPIO_InitTypeDef hKeyPad_GPIOx;


}KeyPad_Handle_t;



/*
 * Functions
 */
void KEYPAD_HwInit(KeyPad_Handle_t hKeyPad);
uint8_t	KEYPAD_ReadPad(void);


#endif /* NUMKEYS_PAD_H_ */
