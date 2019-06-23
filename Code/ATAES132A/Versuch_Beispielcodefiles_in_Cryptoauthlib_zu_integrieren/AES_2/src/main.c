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
#include "usart_conf.h"
#include "aes132_comm_marshaling.h"

// Macros
#define PACKET_BLOCK_SIZE_MAX    (256)
char string[200] = {0};
char input_string[32] = {0};
uint16_t word_address = 0x0000;
uint16_t rx_byte_count = 0x0004;
uint8_t tx_buffer_write[] = {0x55, 0xAA, 0xBC, 0xDE}; // Data to be written
uint8_t aes132_lib_return, serial_data;

// Global variables for SPI/I2C interface
uint8_t tx_buffer[84];
uint8_t rx_buffer[36];

// Global variables for serial
uint8_t  g_packet_block[PACKET_BLOCK_SIZE_MAX];
uint16_t g_packet_block_index;




int main (void)
{
	system_init();
	configureUsart();

	aes132p_enable_interface();

		usartClearWindow();
		strcpy(string, "ATECC132A                           \n\r");
		usartWriteBuffer(string, sizeof(string));
		write_memory_test();

	while (1) {
		//usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		//strcpy(string, "Please enter the message:             \n\r");
		//usartWriteBuffer(string, sizeof(string));
		//usartReadString(input_string, sizeof(input_string));
	}
	
	aes132p_disable_interface();

}
