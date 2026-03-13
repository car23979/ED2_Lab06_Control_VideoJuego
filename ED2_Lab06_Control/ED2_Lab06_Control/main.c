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
	
	//
}

