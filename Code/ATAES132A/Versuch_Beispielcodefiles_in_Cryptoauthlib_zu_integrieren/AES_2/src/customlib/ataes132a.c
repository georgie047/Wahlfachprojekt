/*
 * ataesa.c
 *
 * Created: 22.06.2019 14:31:38
 *  Author: nathalie
 */ 
#include "ataes132a.h"
#include "asf.h"
#include "cryptoauthlib.h"
#include "usart_conf.h"

void getsAtaesSerialNumber(void){
	uint8_t sernum[9];
	ATCA_STATUS status;

	status = atcab_read_serial_number(sernum);
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	else{
		usartWriteHex(sernum, sizeof(sernum));
	}
}