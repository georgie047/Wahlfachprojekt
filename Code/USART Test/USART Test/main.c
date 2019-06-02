#include <atmel_start.h>


int main(void)
{
	uint8_t chr[1] = "b";
	uint8_t str[30] = "USART Enabled\n\r";
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART, &io);
	usart_sync_enable(&USART);

	io_write(io, str, 15);
	io_write(io, (uint8_t *) "Enter Text\n\r", 12);

	
	/* Replace with your application code */
	while (1) {
		io_read(io,chr, 1);
		io_write(io, chr, 1);
		//delay_ms(1000);
	}
}
