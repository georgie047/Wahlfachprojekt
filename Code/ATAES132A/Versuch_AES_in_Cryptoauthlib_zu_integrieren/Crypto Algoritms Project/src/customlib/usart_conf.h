/*
 * usart_conf.h
 *
 * Created: 04/06/2019 10:52:48
 *  Author: christopher
 */ 
 struct usart_module USART;
 void configureUsart(void);

 void usartWriteBuffer(const char *tx_data, uint16_t length);
 void usartWriteHex(const uint8_t *tx_data,uint16_t length);
 void usartNewline(void);

uint8_t usartReadNumb(void);
void usartReadString(char* string, uint16_t length);

void usartClearWindow(void);



void usartLoadingScreen(int ms);

uint16_t length(char* string);