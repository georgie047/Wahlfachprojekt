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
#include <asf.h>
#include <string.h>

//Custom Headers
#include "usart_conf.h"
#include "aes132_comm_marshaling.h"

// Macros
#define PACKET_BLOCK_SIZE_MAX    (256)

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


/** \brief Converting Nibble to ASCII hex
 *
 * \param data is nibble data to be converted
 *
 * \return data is the ASCII hex value
**/
/*uint8_t nibble_to_hex(uint8_t data)
{
	data &= 0x0F;
	if (data <= 0x09) {
		// 0x0-0x9
		data += '0';
	} else {
		// 0xA-0xF
		data = data - 10 + 'A';
	}
	return data;
}*/

/** \brief Converting ASCII hex to nibble
 *
 * \param data is the ASCII hex value to be converted
 *
 * \return data is the nibble value
**/
/*uint8_t hex_to_nibble(uint8_t data)
{
	if ((data >= '0') && (data <= '9' )) {
		// Numbers (0-9)
		data -= '0';
	} else if ((data >= 'A') && (data <= 'F' )) {
		// Uppercase (A-F)
		data = data -'A' + 10;
	} else if ((data >= 'a') && (data <= 'f' )) {
		// Lowercase (a-f)
		data = data -'a' + 10;
	} else {
		// Illegal
		data = 0;
	}
	
	return data;
}*/

/** \brief Parses a byte from the argument, put the parsed data into a global array.
 *         Uses static variables and global variables.
 *         Set #PACKET_BLOCK_SIZE_MAX define in parser.h to maximum buffer size needed.
 *
 *  \param serial_data Data input
 *  \return 1 on complete parsing, 0 otherwise
 */

/*uint8_t parse_command(uint8_t serial_data)
{
	static unsigned char parser_state, nibble_value;
	char string[90] = {0};
	
	switch (parser_state) {
		case 0:
			g_packet_block_index = 0;
			if (serial_data == '(') {
				parser_state = 1;
			} else {
				usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
				strcpy(string, "Input:             \n\r");
				usartWriteBuffer(string, sizeof(string));
				strcpy(string, serial_data);
				usartWriteBuffer(string, sizeof(string));
			}
			break;
		case 1:
			nibble_value = hex_to_nibble(serial_data);
			parser_state = 2;
			break;
		case 2:
			g_packet_block[g_packet_block_index] = (nibble_value << 4) + hex_to_nibble(serial_data);
			if (g_packet_block_index < PACKET_BLOCK_SIZE_MAX - 1) {
				g_packet_block_index++;
			} else {
				strcpy(string, "Error buffer overflow             \n\r");
				usartWriteBuffer(string, sizeof(string));
			}
			parser_state = 3;
			break;
		case 3:
			if (serial_data == ' ') {
				parser_state = 1;
			} else if (serial_data == ')') {
				parser_state = 0;
				usartNewline();
				return 1;
			} else {
				parser_state = 0;
			}
			break;
		default:
			parser_state = 0;
	} // switch (parser_state)
	
	return 0;
}*/

// Write memory test
uint8_t write_memory_test(void)
{
	char string[90] = {0};
	// -------------------- Write memory. -----------------------------------
	// Don't put this in an infinite loop. Otherwise the non-volatile memory will wear out.
	aes132_lib_return = aes132m_write_memory(sizeof(tx_buffer_write), word_address, tx_buffer_write);
	if (aes132_lib_return != AES132_FUNCTION_RETCODE_SUCCESS) {
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "Write memory failed!             \n\r");
		usartWriteBuffer(string, sizeof(string));
		return aes132_lib_return;
	}
	strcpy(string, "Write memory success!             \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "Data:             \n\r");
	usartWriteBuffer(string, sizeof(string));
	usartWriteHex(tx_buffer_write, sizeof(tx_buffer_write));
	strcpy(string, "\n\r");
	usartWriteBuffer(string, sizeof(string));
}

// Read memory test
uint8_t read_memory_test(void)
{
	char string[90] = {0};
	// -------------------- Read memory. -----------------------------------
	aes132_lib_return = aes132m_read_memory(rx_byte_count, word_address, rx_buffer);
	if (aes132_lib_return != AES132_FUNCTION_RETCODE_SUCCESS) {
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "Read memory failed!             \n\r");
		usartWriteBuffer(string, sizeof(string));
		return aes132_lib_return;
	}
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "Read memory success!             \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "Data:             \n\r");
	usartWriteBuffer(string, sizeof(string));
	usartWriteHex(rx_buffer, sizeof(tx_buffer_write));
	strcpy(string, "\n\r");
	usartWriteBuffer(string, sizeof(string));
	// -------------------- Compare written with read data. -----------------------------------
	aes132_lib_return =  memcmp(tx_buffer_write, rx_buffer, sizeof(tx_buffer_write));
	if (aes132_lib_return != AES132_FUNCTION_RETCODE_SUCCESS) {
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "Compare Memory mismatch!             \n\r");
		usartWriteBuffer(string, sizeof(string));
		return aes132_lib_return;
	}
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "Compare Memory match!             \n\r");
	usartWriteBuffer(string, sizeof(string));
}

// Send a BlockRead command
uint8_t block_read_test(void)
{
	char string[90] = {0};
	// ------- Send a BlockRead command and receive its response. -----------------------------
	aes132_lib_return = aes132m_execute(AES132_BLOCK_READ, 0, word_address, rx_byte_count,
	0, NULL, 0, NULL, 0, NULL, 0, NULL, tx_buffer, rx_buffer);
	if (aes132_lib_return != AES132_FUNCTION_RETCODE_SUCCESS) {
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "Block Read memory failed!             \n\r");
		usartWriteBuffer(string, sizeof(string));
		return aes132_lib_return;
	}
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "Block Read memory success!             \n\r");
	usartWriteBuffer(string, sizeof(string));
	strcpy(string, "Data:             \n\r");
	usartWriteBuffer(string, sizeof(string));
	usartWriteHex(&rx_buffer[AES132_RESPONSE_INDEX_DATA], rx_byte_count);
		
	// -------------------- Compare written with read data. -----------------------------------
	aes132_lib_return =  memcmp(tx_buffer_write, &rx_buffer[AES132_RESPONSE_INDEX_DATA], sizeof(tx_buffer_write));
	if (aes132_lib_return != AES132_FUNCTION_RETCODE_SUCCESS) {
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "Compare Memory mismatch!             \n\r");
		usartWriteBuffer(string, sizeof(string));
		return aes132_lib_return;
	}
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "Compare Memory match!             \n\r");
	usartWriteBuffer(string, sizeof(string));
}


void aes132app_single_execute(void)
{
	char string[90] = {0};
	uint8_t* p_packet_block = g_packet_block;
	
	uint8_t  op_code  = 0;
	uint8_t  mode	  = 0;
	uint16_t param1   = 0;
	uint16_t param2   = 0;
	uint8_t  datalen1 = 0;
	uint8_t* data1    = NULL;
	uint8_t  datalen2 = 0;
	uint8_t* data2    = NULL;
	uint8_t  datalen3 = 0;
	uint8_t* data3    = NULL;
	uint8_t  datalen4 = 0;
	uint8_t* data4    = NULL;
	uint8_t  ret_code = 0xFF;

	// 4 bytes Opcode, Param1, Param2
	op_code  =  *p_packet_block++;
	mode	 =	*p_packet_block++;
	param1   = (*p_packet_block++ << 8);
	param1  |= (*p_packet_block++);
	param2   = (*p_packet_block++ << 8);
	param2  |= (*p_packet_block++);
	
	// The rest is included as Data1
	datalen1 = g_packet_block_index - 6;
	data1    = p_packet_block;
	
	// Execute
	ret_code = aes132m_execute(op_code,mode, param1, param2,
	datalen1, data1, datalen2, data2, datalen3, data3,
	datalen4, data4, tx_buffer, rx_buffer);
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "\n\r TX buffer = 0x");
	usartWriteBuffer(string, sizeof(string));
	usartWriteHex(tx_buffer, tx_buffer[0]);
	strcpy(string, "\n");
	usartWriteBuffer(string, sizeof(string));
	if(ret_code == AES132_FUNCTION_RETCODE_SUCCESS){
		usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
		strcpy(string, "\n\r RX buffer = 0x");
		usartWriteBuffer(string, sizeof(string));
		usartWriteHex(rx_buffer, rx_buffer[0]);
		strcpy(string, "\n");
		usartWriteBuffer(string, sizeof(string));
	}else
		strcpy(string, "Failed! ret_code = 0x");
		usartWriteBuffer(string, sizeof(string));
		strcpy(string, ret_code);
		usartWriteBuffer(string, sizeof(string));
		strcpy(string, "\n");
		usartWriteBuffer(string, sizeof(string));
}


void aes132app_command_dispatch(void)
{
	char string[90] = {0};
	// Dispatch appropriate function, deduce from the opcode (packet block byte #0)
	// Use dummy opcodes for specific cases
	usart_write_buffer_wait(&USART, (uint8_t *)"\033[5B", 6);
	strcpy(string, "Choose a function:");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	strcpy(string, "1) write memory test ");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	strcpy(string, "2) read memory test ");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	strcpy(string, "3) block read test ");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	strcpy(string, "4) aes132app single execute ");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	if(usartReadNumb() == 1)
	{
		write_memory_test();
	}
	else if(usartReadNumb() == 2)
	{
		read_memory_test();
	}
	else if(usartReadNumb() == 3)
	{
		block_read_test();
	}
	else if(usartReadNumb() == 4)
	{
		aes132app_single_execute();
	}
	else
	{
		strcpy(string, "Invalid number!!");
		usartWriteBuffer(string, sizeof(string));
	}
}

/** \brief This function is the entry function for an example application that
           uses the AES132 library.
 * \return result (0: success, otherwise failure)
 */
int main(void)
{
	char string[90] = {0};
	//! [system_init]
	system_init();
	//! [system_init]
	
	//! [aes132p_enable_interface]
	//aes132p_enable_interface();
	//! [aes132p_enable_interface]
	configureUsart();
	strcpy(string, "*****AES132 TEST*****");
	usartWriteBuffer(string, sizeof(string));
	usartNewline();
	while(1){
		//serial_data = usartReadNumb();
		//if (serial_data > 0){
				//if (parse_command(serial_data))
				aes132app_command_dispatch();
		//};
	}
	//aes132p_disable_interface();

	return aes132_lib_return;
}
