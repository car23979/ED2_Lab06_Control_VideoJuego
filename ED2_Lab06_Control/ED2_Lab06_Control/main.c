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
		
		// Botón izquierda (PD4)
		if (!(PIND & (1 << PIND4)))
		{
			UART_sendChar('Left');
			_delay_ms(200);
		}
		
		// Botón derecha (PD5)
		if (!(PIND & (1 << PIND5)))
		{
			UART_sendChar('Right');
			_delay_ms(200);
		}
		
		// Botón A (PD6)
		if (!(PIND & (1 << PIND6)))
		{
			UART_sendChar('A');
			_delay_ms(200);
		}
		
		// Botón B (PD7)
		if (!(PIND & (1 << PIND7)))
		{
			UART_sendChar('B');
			_delay_ms(200);
		}
	}
}

// Implementación de inicialización UART
void UART_Init(uint32_t baud) 
{
	// Cálculo del valor UBRR para 115200 baudios a 16 MHz
	uint16_t ubrr_value = (F_CPU / (16 * baud)) - 1;
	
	UBRR0H = (uint8_t)(ubrr_value >> 8);
	UBRR0L = (uint8_t)ubrr_value;
	
	//  
}

