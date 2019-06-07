/*
 * ateccx08a.c
 *
 * Created: 07/06/2019 09:12:58
 *  Author: christopher
 */ 

 #include <asf.h>
 #include "ateccx08a.h"
 #include "cryptoauthlib.h"
 #include "usart_conf.h"


 bool generateKeyPair (uint8_t* pub_key){
	ATCA_STATUS status;
	//uint8_t key[64] = {0};

	
	status = atcab_genkey(0x0000, pub_key);
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
		return false;
	}
	return true;
 }

void isDeviceLocked (void){
	ATCA_STATUS status;
	bool dataIsLocked = 0xff, cfgIsLocked = 0xff;

	  
	status = atcab_is_locked(LOCK_ZONE_CONFIG, &cfgIsLocked);

	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	else{
		
		if(cfgIsLocked){usart_write_buffer_wait(&USART, (uint8_t *)"Config is locked\n\r", 20);}
		else{usart_write_buffer_wait(&USART, (uint8_t *)"Config is not locked\n\r", 22);}
	}

	status = atcab_is_locked(LOCK_ZONE_DATA, &dataIsLocked);

	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	else{
		if(dataIsLocked){usart_write_buffer_wait(&USART, (uint8_t *)"Data is locked\n\r", 20);}
		else{usart_write_buffer_wait(&USART, (uint8_t *)"Data is not locked\n\r", 22);}
	}
}

void lockZones(void){
	ATCA_STATUS status;
	uint8_t input = 0;

	usart_write_buffer_wait(&USART, (uint8_t *)"1)Lock Config\n\r", 16);
	usart_write_buffer_wait(&USART, (uint8_t *)"2)Lock Data\n\r", 16);
	input = usartReadNumb();

	if(input == 1){
		status = atcab_lock_config_zone();
		if(status != ATCA_SUCCESS){
			port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
			usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
		}
	}
	else if (input == 2){
		status = atcab_lock_data_zone();
		if(status != ATCA_SUCCESS){
			port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
			usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
		}

	}



}

 void generateRandom (void){
 	ATCA_STATUS status;
 	uint8_t rand[32] = {0};
 	
 	status = atcab_random(rand);
 	if(status != ATCA_SUCCESS){
	 	port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
	 	usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
 	}
	else{
		usartWriteHex(rand, sizeof(rand));
	}
 
 }

