/*
 * This is a file for store all the Keyboard keys Hex value, to send it trough the USB protocol as Keyboard.
 */

#ifndef INC_KEYBOARD_KEYS_H_
#define INC_KEYBOARD_KEYS_H_

/*-------------------------------------------------------------------------------------------------------
 * INCLUDES
 --------------------------------------------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "usb_device.h"



/*-------------------------------------------------------------------------------------------------------
 * DEFINES
 --------------------------------------------------------------------------------------------------------*/


/*Keyboard's Key Value to send through USB (INCOMPLETE)*/

#define KEY_RELEASE				0x00
#define KEY_a					0x04
#define KEY_b					0x05
#define KEY_c					0x06
#define KEY_d					0x07
#define KEY_e					0x08
#define KEY_f					0x09
#define KEY_g					0x0A
#define KEY_h					0x0B
#define KEY_i					0x0C
#define KEY_j					0x0D
#define KEY_k					0x0E
#define KEY_l					0x0F
#define KEY_m					0x10
#define KEY_n					0x11
#define KEY_o					0x12
#define KEY_p					0x13
#define KEY_q					0x14
#define KEY_r					0x15
#define KEY_s					0x16
#define KEY_t					0x17
#define KEY_u					0x18
#define KEY_v					0x19
#define KEY_w					0x1A
#define KEY_x					0x1B
#define KEY_y					0x1C
#define KEY_z					0x1D

#define KEY_0					0x27
#define KEY_1					0x1E
#define KEY_2					0x1F
#define KEY_3					0x20
#define KEY_4					0x21
#define KEY_5					0x22
#define KEY_6					0x23
#define KEY_7					0x24
#define KEY_8					0x25
#define KEY_9					0x26

#define KEY_SPACE				0x2C
#define KEY_DELETE				0x2A
#define KEY_CAPSLOCK			0x39

#define KEY_F1					0x3A
#define KEY_F2					0x3B
#define KEY_F3					0x3C
#define KEY_F4					0x3D
#define KEY_F5					0x3E
#define KEY_F6					0x3F
#define KEY_F7					0x40
#define KEY_F8					0x41
#define KEY_F9					0x42
#define KEY_F10					0x43
#define KEY_F11					0x44
#define KEY_F12					0x45

//There is more, Check: HID_USB_ReferenceManual.PDF section 10 "Keyboard/Keypad Page" for more Keys.



/*Time for Press status and Release Keys*/
#define DELAY_MS_PRESSING		50u
#define DELAY_MS_RELEASE		DELAY_MS_PRESSING

/*-------------------------------------------------------------------------------------------------------
 * STRUCTS
 --------------------------------------------------------------------------------------------------------*/






/*-------------------------------------------------------------------------------------------------------
 * PROCESSES
 --------------------------------------------------------------------------------------------------------*/
void USB_KEYBOARD_SEND(uint8_t *word,uint16_t Size);



#endif /* INC_KEYBOARD_KEYS_H_ */
