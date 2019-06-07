/*
 * atsha204a.c
 *
 * Created: 06/06/2019 09:11:07
 *  Author: christopher
 */ 
 #include <asf.h>
 #include "atsha204a.h"
 #include "cryptoauthlib.h"
 #include "usart_conf.h"

 void getsAtshaSerialNumber(void){
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

  void hashMessage(const uint8_t * data,uint16_t length){
	  ATCA_STATUS status;
	  uint8_t hash[32] = {0x00};
	  status = atcab_hw_sha2_256(data, length, hash);

	  if(status != ATCA_SUCCESS){
		  port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		  usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	  }
	  else{
		usartWriteHex(hash, sizeof(hash));
	  }
  }


  void hmac (void){
	ATCA_STATUS status;
	//status=atacb_der;
	/*

	uint8_t key[32] = {0x00};
	status=atcab_nonce(key);
	
	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	else{
		usartWriteHex(key, sizeof(key));
	}*/



	//uint8_t key08[32] = {0x88,0x88,0xC6,0x2A,0xFE,0x1F,0x82,0xD4,0xE0,0x85,0x85,0x34,0x4D,0x77,0xB8,0x9D,0xEC,0x36,0xF2,0x06,0x27,0xE4,0xF0,0xCF,0x03,0x0E,0x27,0xB8,0xEE,0xE3,0x88,0x88};
	
	
	uint8_t challenge[32] = {
		0xAB,0x97,0xFC,0x3D,
		0x40,0x8D,0x55,0x10,
		0x56,0x5C,0x51,0x1C,
		0xD0,0x86,0x03,0xDB,
		0x24,0x27,0x07,0x92,
		0x6B,0x13,0xF1,0x7F,
		0x6D,0x5B,0x5B,0xE1,
		0x4B,0x5F,0x2C,0x50
	};

	uint8_t mac[32] = {0x00};
	uint8_t mode = 0x00;
	uint8_t key_id = 0x08;
	status = atcab_mac(mode, 0x00 + key_id, challenge ,mac);

	if(status != ATCA_SUCCESS){
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		usart_write_buffer_wait(&USART, (uint8_t *)"Some problem occurred!\n\r", 22);
	}
	else{
		usartWriteHex(mac, sizeof(mac));
	 }

  }