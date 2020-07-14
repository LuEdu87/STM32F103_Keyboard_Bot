
#include "NumKeys_Pad.h"










/*
 * STATIC FUNCTION DECLARATION
 */

static void KeyPad_ClkGPioEna(void);



/*
 * STATIC FUNCTION DESCRIPTION
 */
static void KeyPad_ClkGPioEna(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

}





/*--------------------------------------------------------
 * CONFIGURATION HARDWARE FOR PINS TO KEYPAD
 * (SEE header file(NumKeys_Pad.h) to change the pins in case)
 ---------------------------------------------------------*/
void KEYPAD_HwInit(KeyPad_Handle_t hKeyPad)
{
	KeyPad_ClkGPioEna();



	hKeyPad.hKeyPad_GPIOx.Speed = GPIO_SPEED_FREQ_LOW;



	//Outputs Pins Configuration
	hKeyPad.hKeyPad_GPIOx.Mode = GPIO_MODE_OUTPUT_PP;

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_5_Number;
	HAL_GPIO_Init(Pin_5_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_6_Number;
	HAL_GPIO_Init(Pin_6_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_7_Number;
	HAL_GPIO_Init(Pin_7_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_8_Number;
	HAL_GPIO_Init(Pin_8_Letter, &hKeyPad.hKeyPad_GPIOx);

	HAL_GPIO_WritePin(Pin_5_Letter, Pin_5_Number, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Pin_6_Letter, Pin_6_Number, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Pin_7_Letter, Pin_7_Number, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Pin_8_Letter, Pin_8_Number, GPIO_PIN_SET);




	//Inputs Pins Configuration
	hKeyPad.hKeyPad_GPIOx.Pull = GPIO_PULLUP;
	hKeyPad.hKeyPad_GPIOx.Mode = GPIO_MODE_INPUT;

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_1_Number;
	HAL_GPIO_Init(Pin_1_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_2_Number;
	HAL_GPIO_Init(Pin_2_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_3_Number;
	HAL_GPIO_Init(Pin_3_Letter, &hKeyPad.hKeyPad_GPIOx);

	hKeyPad.hKeyPad_GPIOx.Pin = Pin_4_Number;
	HAL_GPIO_Init(Pin_4_Letter, &hKeyPad.hKeyPad_GPIOx);



}








/*
 * This function return an ASCII value of the Key we pressed in the Arduino's Keypad
 * I use this because only use 8 pins for 16 keys. So you can send over 16 combinations of phrases
 * through the Keyboard USB protocol.
 */



uint8_t	KEYPAD_ReadPad(void)
{

	for(uint8_t i=0;i<Column_Size;i++)
	{
		HAL_GPIO_WritePin(Pin_5_Letter, Pin_5_Number, (~(0x01>>i) & 1));
		HAL_GPIO_WritePin(Pin_6_Letter, Pin_6_Number, (~(0x02>>i) & 1));
		HAL_GPIO_WritePin(Pin_7_Letter, Pin_7_Number, (~(0x04>>i) & 1));
		HAL_GPIO_WritePin(Pin_8_Letter, Pin_8_Number, (~(0x08>>i) & 1));



		switch(i)
		{
			case 0:
					 if(!HAL_GPIO_ReadPin(Pin_1_Letter, Pin_1_Number))
					 {
						 return Pressed_D;

					 }else if(!HAL_GPIO_ReadPin(Pin_2_Letter, Pin_2_Number) )
					 {
						 return Pressed_HashT;

					 }else if(!HAL_GPIO_ReadPin(Pin_3_Letter, Pin_3_Number))
					 {
						 return Pressed_0;

					 }else if(!HAL_GPIO_ReadPin(Pin_4_Letter, Pin_4_Number))
					 {
						 return Pressed_Aste;
					 }else

				break;


			case 1:
					if(HAL_GPIO_ReadPin(Pin_1_Letter, Pin_1_Number) == 0)
					 {
						 return Pressed_C;

					 }else if(HAL_GPIO_ReadPin(Pin_2_Letter, Pin_2_Number) == 0)
					 {
						 return Pressed_9;

					 }else if(HAL_GPIO_ReadPin(Pin_3_Letter, Pin_3_Number) == 0)
					 {
						 return Pressed_8;

					 }else if(HAL_GPIO_ReadPin(Pin_4_Letter, Pin_4_Number) == 0)
					 {
						 return Pressed_7;
					 }else


				break;


			case 2:
					if(HAL_GPIO_ReadPin(Pin_1_Letter, Pin_1_Number) == 0)
					{
					 return Pressed_B;

					}else if(HAL_GPIO_ReadPin(Pin_2_Letter, Pin_2_Number) == 0)
					{
					 return Pressed_6;

					}else if(HAL_GPIO_ReadPin(Pin_3_Letter, Pin_3_Number) == 0)
					{
					 return Pressed_5;

					}else if(HAL_GPIO_ReadPin(Pin_4_Letter, Pin_4_Number) == 0)
					{
					 return Pressed_4;
					}else
				break;


			case 3:
					if(HAL_GPIO_ReadPin(Pin_1_Letter, Pin_1_Number) == 0)
					{
					 return Pressed_A;

					}else if(HAL_GPIO_ReadPin(Pin_2_Letter, Pin_2_Number) == 0)
					{
					 return Pressed_3;

					}else if(HAL_GPIO_ReadPin(Pin_3_Letter, Pin_3_Number) == 0)
					{
					 return Pressed_2;

					}else if(HAL_GPIO_ReadPin(Pin_4_Letter, Pin_4_Number) == 0)
					{
					 return Pressed_1;
					}else

				break;


			default:
				return 0;
				break;
		}
	}

	return 0;
}
