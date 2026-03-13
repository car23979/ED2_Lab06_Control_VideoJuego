/*
 * ED2_Lab06_Control.c
 *
 * Created: 12/03/2026 05:31:56 p. m.
 * Author : David Carranza
 * Carnet : 23979
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>

// Prototipos de funciones
void UART_Init(uint32_t baud);
void UART_sendChar(char data);

int main(void)
{
	// Configuración de Botones (GPIO)
	// Definir PD2 a PD7 como entradas
	DDRD &= ~((1 << DDD2) | (1 << DDD3) ! (1 << DDD4) | (1 << DDD5) | (1 << DDD6) | (1 << DDD7));
	
	// Pull up interno
	PORTD |= (1 << PORTD2) | (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7);
	
	// Inicialización de UART a 115200 baudios
	UART_Init(115200);
	
	while(1)
	{
		// Se lee el registro PIND para detectar pulsaciones
		
		// Botón arriba (PD2)
		if (!(PIND & (1 << PIND2)))
		{
			UART_sendChar('Up');
			_delay_ms(200);
		}
		
		// Botón abajo (PD3)
		if (!(PIND & (1 << PIND3)))
		{
			UART_sendChar('Down');
			_delay_ms(200);
		}
		
		// Botón derecha (PD4)
		if (!(PIND & (1 << PIND4)))
		{
			UART_sendChar('Right');
			_delay_ms(200);
		}
	}
}

