/*
 * This is a file for store all the Keyboard keys Hex value, to send it trough the USB protocol as Keyboard.
 */


#include "Keyboard_Keys.h"


extern USBD_HandleTypeDef hUsbDeviceFS;




/*
 * A USB function for send directly the buffer's words that we want to write with the Keyboard.
 *  Param: word -> Array of letters
 *  Param: Size -> the size of the buffer to use in the "for" loop.
 */

void USB_KEYBOARD_SEND(uint8_t word[],uint16_t Size)
{
	uint8_t Keys[8] = {0};


	for(uint8_t i=0; i<Size;i++)
	{
		Keys[7] = word[i];
		USBD_HID_SendReport(&hUsbDeviceFS, Keys, 8);
		HAL_Delay(DELAY_MS_PRESSING);
		Keys[7] = KEY_RELEASE;
		USBD_HID_SendReport(&hUsbDeviceFS, Keys, 8);
		HAL_Delay(DELAY_MS_RELEASE);
	}

}
