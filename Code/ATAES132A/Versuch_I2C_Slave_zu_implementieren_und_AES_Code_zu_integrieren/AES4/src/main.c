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
#include "usart_conf.h"
#include <string.h>
#include "i2c_slave.h"
#define DATA_LENGTH 10
uint8_t write_buffer[DATA_LENGTH] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
};
uint8_t read_buffer[DATA_LENGTH];
#define SLAVE_ADDRESS 0x50
struct i2c_slave_module i2c_slave_instance;
#define CONF_I2C_SLAVE_MODULE CRYPTO_AES_BUILD_MODE_ECB

void configure_i2c_slave(void)
{
	/* Create and initialize config_i2c_slave structure */
	struct i2c_slave_config config_i2c_slave;
	i2c_slave_get_config_defaults(&config_i2c_slave);
	/* Change address and address_mode */
	config_i2c_slave.address = SLAVE_ADDRESS;
	config_i2c_slave.address_mode = I2C_SLAVE_ADDRESS_MODE_MASK;
	config_i2c_slave.buffer_timeout = 1000;
	/* Initialize and enable device with config_i2c_slave */
	i2c_slave_init(&i2c_slave_instance, CONF_I2C_SLAVE_MODULE, &config_i2c_slave);
	i2c_slave_enable(&i2c_slave_instance);
}


int main (void)
{
	char string[40] = {0};
	
	system_init();
	configureUsart();

	configure_i2c_slave();
	enum i2c_slave_direction dir;
	struct i2c_slave_packet packet = {
		.data_length = DATA_LENGTH,
		.data = write_buffer,
	};
	
	/* Insert application code here, after the board has been initialized. */
	
	usartClearWindow();
	strcpy(string, "ATAES132A                           \n\r");
	usartWriteBuffer(string, sizeof(string));
	
	/* This skeleton code simply sets the LED to the state of the button. */
	while (1) {
		dir = i2c_slave_get_direction_wait(&i2c_slave_instance);
		/* Transfer packet in direction requested by master */
		if (dir == I2C_SLAVE_DIRECTION_READ) {
			packet.data = read_buffer;
			i2c_slave_read_packet_wait(&i2c_slave_instance, &packet);
			} else if (dir == I2C_SLAVE_DIRECTION_WRITE) {
			packet.data = write_buffer;
			i2c_slave_write_packet_wait(&i2c_slave_instance, &packet);
		}
	}
}
