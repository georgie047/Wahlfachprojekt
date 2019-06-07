/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
//Header
#include <asf.h>
#include <string.h>

//Custom Headers
#include "cryptoauthlib.h"
#include "usart_conf.h"
#include "atsha204a.h"
#include "ateccx08a.h"

//Globals
char string[40] = {0};
char input_string[32] = {0};
uint8_t input;

uint8_t pub_key[64] = {0};
uint8_t message[32] = {0};

uint8_t sernum[9];
ATCA_STATUS status;

//Prototypes
void menu (void);
void atsha204a_menu (void);
void ateccx08a_menu (void);

int main (void)
{
	system_init();
	configureUsart();

	/*
	port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
	status = atcab_init(&cfg_ateccx08a_i2c_default);
	
	if(status == ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
	}
	status = atcab_wakeup();
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
	}
	*/

	/*delay_s(1);
	status = atcab_read_serial_number(sernum);


	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
	}
	uint8_t data[] = {0x41,0x42,0x43,0x44};
	uint8_t hash[32] = {0x00};
	status = atcab_hw_sha2_256(data, sizeof(data), hash);

	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
	}
	*/
	while (1) {
		menu();
	}


}



void menu (void){


	usartClearWindow();
	strcpy(string, "Menu                                  \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "1)ATSHA204A                           \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "2)ATECCx08A                           \n\r");
	usartWriteBuffer(string, sizeof(string));
	input = usartReadNumb();


	if(input == 1){
		atsha204a_menu();

	}else if (input == 2){
		ateccx08a_menu();
	}
}

void atsha204a_menu (void){
	bool changeMenu = false;
	//Starting i2c connection
	status = atcab_init(&cfg_atsha204a_i2c_default);
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}

	//Wake up i2c slave
	status = atcab_wakeup();
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	usartLoadingScreen(3000);
	input = 0;
	
	while(!changeMenu){
		usartClearWindow();
		strcpy(string, "ATSHA204A Menu                        \n\r");
		usartWriteBuffer(string, sizeof(string));
		strcpy(string, "1) Get Serial number of ATSHA204A Chip\n\r");
		usartWriteBuffer(string, sizeof(string));
		strcpy(string, "2) Hash Message                       \n\r");
		usartWriteBuffer(string, sizeof(string));
		strcpy(string, "3) Change Chip                        \n\r");
		usartWriteBuffer(string, sizeof(string));
		

		switch(input){
			case 0:
				break;
			
			case 1:	
				usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
				strcpy(string, "Serial number:                        \n\r");
				usartWriteBuffer(string, sizeof(string));
				getsAtshaSerialNumber();
				break;
			
			case 2:	
				usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
				strcpy(string, "Please enter the message:             \n\r");
				usartWriteBuffer(string, sizeof(string));
				usartReadString(input_string, sizeof(input_string));
				strcpy(string, "Hashed message:                       \n\r");
				usartWriteBuffer(string, sizeof(string));
				hashMessage((uint8_t*)input_string,length(input_string));
				break;
			
			case 3:
				changeMenu = true;
				break;
			
			default:
				strcpy(string, "Please enter a number between 1 and x \n\r");
				usartWriteBuffer(string, sizeof(string));
				break;
		}
		if(input != 3){
		input = usartReadNumb();
		}
	}

}

void ateccx08a_menu (void){
	

	bool changeMenu = false;
	//Starting i2c connection
	status = atcab_init(&cfg_ateccx08a_i2c_default);

	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}

	//Wake up i2c slave
	status = atcab_wakeup();
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	
	usartLoadingScreen(3000);
	input = 0;




while(!changeMenu){
	usartClearWindow();
	strcpy(string, "ATSHA204A Menu                        \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "1) Get Serial number of ATSHA204A Chip\n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "2) Check if device is locked          \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "3) Lock Zones                         \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "4) Generate random number             \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "5) Generate Key                       \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "6) Change Chip                        \n\r");
	usartWriteBuffer(string, sizeof(string));
	

	switch(input){
		case 0:
		break;
		case 1:		
			usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
			strcpy(string, "Serial number:                        \n\r");
			usartWriteBuffer(string, sizeof(string));
			getsAtshaSerialNumber();
			break;

		case 2:
			usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
			isDeviceLocked();
			break;
		
		case 3:
			usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
			lockZones();
			break;		
		
		
		case 4:
			usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
			strcpy(string, "Random number:                        \n\r");
			usartWriteBuffer(string, sizeof(string));
			generateRandom();
			break;

		case 5:
			usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
			strcpy(string, "Public key:                           \n\r");
			usartWriteBuffer(string, sizeof(string));
			if(generateKeyPair(pub_key)){
			usartWriteHex(pub_key, sizeof(pub_key));
			}
			break;

		case 6:
			changeMenu = true;
			break;
		default:
			strcpy(string, "Please enter a number between 1 and 6 \n\r");
			usartWriteBuffer(string, sizeof(string));
			break;
	}
	if(input != 6){
		input = usartReadNumb();
	}
}

}