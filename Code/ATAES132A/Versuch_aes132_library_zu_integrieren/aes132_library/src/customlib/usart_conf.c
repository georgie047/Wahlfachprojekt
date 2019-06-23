/*
 * usart_conf.c
 *
 * Created: 04/06/2019 10:53:09
 *  Author: christopher
 */ 
 #include <asf.h>
 #include "usart_conf.h"
 #include <string.h>

 void configureUsart(void){
	 struct usart_config config_usart;
	 usart_get_config_defaults(&config_usart);
	 config_usart.baudrate    = 115200;
	 config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	 config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	 config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	 config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	 config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
	 while (usart_init(&USART,EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {    }
	 usart_enable(&USART);
 }


void usartWriteBuffer(const char *tx_data,uint16_t length){
	usart_write_buffer_wait(&USART, (uint8_t *)tx_data, length);
}

void usartWriteHex(const uint8_t *tx_data,uint16_t length){
	int numb_hex = 0;
	for(int i = 0; i < length; i++)
	{
		numb_hex = tx_data[i] /16 % 16;
		if(numb_hex < 10){
		usart_write_wait(&USART, numb_hex +'0');
		}
		else{
		usart_write_wait(&USART, numb_hex - 10 +'A');
		}

		numb_hex = tx_data[i] % 16;
		if(numb_hex < 10){
			usart_write_wait(&USART, numb_hex +'0');
		}
		else{
			usart_write_wait(&USART, numb_hex - 10 +'A');
		}

		if(i < length - 1){
			usart_write_wait(&USART, ':');
		}
		else{
			usart_write_wait(&USART, '\n');
			usart_write_wait(&USART, '\r');
		}
	}
}


void usartNewline(void){
	usart_write_buffer_wait(&USART, (uint8_t*) "\n\r", 2);
}

uint8_t usartReadNumb(){
	uint16_t temp;
	bool loop = true;
	uint8_t numb;

	while(loop){
	if (usart_read_wait(&USART, &temp) == STATUS_OK) {
			numb = temp;
			if(numb >= '1' && numb <= '9')	
			{
				loop = false;
			}
		}
	}
	return numb - '0';
}

void usartReadString(char* string, uint16_t length){
	for(uint8_t i = 0; i <length;i++){string[i] = 0;}
	//char string[32] = {0};
	char tempStr[2]={0,0};
	uint16_t temp;
	bool loop = true;
	uint8_t char_;

	while(loop){
		if (usart_read_wait(&USART, &temp) == STATUS_OK) {
			char_ = temp;
			if(char_ >= 'A' && char_ <= 'Z' )
			{
				usart_write_wait(&USART, char_);
				tempStr[0] = char_;
				strcat(string, tempStr);
			} else if(char_ >= 'a' && char_ <= 'z'){
				usart_write_wait(&USART, char_);
				tempStr[0] = char_;
				strcat(string, tempStr);
			} else if(char_ >= '0' && char_ <= '9'){
				usart_write_wait(&USART, char_);
				tempStr[0] = char_;
				strcat(string, tempStr);
			} else if(char_ == '\n' || char_ == '\r'){
				loop = false;
			}
		}
	}
	usart_write_wait(&USART, '\n');
	usart_write_wait(&USART, '\r');
	//usartWriteBuffer(string, sizeof(string));
	//usart_write_wait(&USART, '\n');
	//usart_write_wait(&USART, '\r');
	return;
}


void usartClearWindow(void){
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[2J", 4);
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[0;0H", 6);
}

void usartLoadingScreen(int ms)
{
	char string[40] = {0};
	
	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[--------------------------------------]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);

	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[#######-------------------------------]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);

	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[###############-----------------------]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);

	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[#######################---------------]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);

	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[###############################-------]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);

	usartClearWindow();
	strcpy(string, "Chip gets initialized. Please wait.   \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "[######################################]");
	usartWriteBuffer(string, sizeof(string));
	delay_ms(ms / 5);
}


uint16_t length(char* string){
	uint8_t i = 0;

	while(string[i] != 0){
		i++;
	}
	return i;
}
