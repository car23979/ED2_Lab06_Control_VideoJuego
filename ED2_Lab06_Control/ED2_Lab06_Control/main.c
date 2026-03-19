/*
 * ED2_Lab06_Control.c
 *
 * Created: 12/03/2026 05:31:56 p. m.
 * Author : David Carranza
 * Carnet : 23979
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// --- Prototipos de funciones ---
void UART_Init(uint32_t baud);
void UART_sendChar(char data);

int main(void)
{
	// 1. Configuración de Botones (PD2 a PD7 como entradas)
	DDRD &= ~((1 << DDD2) | (1 << DDD3) | (1 << DDD4) | (1 << DDD5) | (1 << DDD6) | (1 << DDD7));
	
	// 2. Habilitar Pull-ups internos (importante para evitar lecturas falsas)
	PORTD |= (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7);
	
	// 3. Inicializar UART a 115200 baudios
	UART_Init(115200);
	
	while(1)
	{
		// Se lee PIND; si el pin está en 0 (botón presionado), se envía la letra
		
		if (!(PIND & (1 << PIND2))) {
			UART_sendChar('U'); // Up
			_delay_ms(300);     // Antirrebote (Debounce)
		}
		
		if (!(PIND & (1 << PIND3))) {
			UART_sendChar('D'); // Down
			_delay_ms(300);
		}
		
		if (!(PIND & (1 << PIND4))) {
			UART_sendChar('L'); // Left
			_delay_ms(300);
		}
		
		if (!(PIND & (1 << PIND5))) {
			UART_sendChar('R'); // Right
			_delay_ms(300);
		}
		
		if (!(PIND & (1 << PIND6))) {
			UART_sendChar('A'); // Botón A
			_delay_ms(300);
		}
		
		if (!(PIND & (1 << PIND7))) {
			UART_sendChar('B'); // Botón B
			_delay_ms(300);
		}
	}
}

// --- Implementación de UART con Modo Doble Velocidad ---
void UART_Init(uint32_t baud)
{
	// ACTIVAR U2X0: Reduce el error de baud rate de 8.5% a 2.1% para 115200
	UCSR0A |= (1 << U2X0);
	
	// Cálculo de UBRR para modo Doble Velocidad
	// UBRR = (F_CPU / (8 * baud)) - 1
	uint16_t ubrr_value = (F_CPU / (8 * baud)) - 1;
	
	UBRR0H = (uint8_t)(ubrr_value >> 8);
	UBRR0L = (uint8_t)ubrr_value;
	
	// Habilitar solo Transmisión (TX)
	UCSR0B = (1 << TXEN0);
	
	// Formato: 8 bits de datos, 1 bit de parada
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_sendChar(char data)
{
	// Esperar a que el buffer esté vacío
	while (!(UCSR0A & (1 << UDRE0)));
	// Enviar dato
	UDR0 = data;
}