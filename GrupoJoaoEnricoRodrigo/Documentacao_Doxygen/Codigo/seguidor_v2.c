// Definições apresentadas em aula para tratamento de bit

#include <avr/io.h>
#include <avr/interrupt.h>

void selecionandoEntradasESaidas(){
	/*
	Configuração de I/O:
      	0 - Entrada
      	1 - Saída
	PORTD: 01 10 00 00
        	Bit 2 e 3 Sensores
        	Bit 5 e 6 Motores
	*/

	DDRD = 0b01100000;
}

void ligandoInterrupcoes() {	
	/*
	Selecionar/Ativar o INT0 e INT 1
		EIMSK: 00 00 00 11
	Iremos configurar os dois esquemas de interrupção para que ativem quando houver alteração lógica.
		ou seja:
			EICRA: 00 00 01 01
	E iremos habilitar as interrupções globais.
	*/
	
	EIMSK = 0b00000011;
	EICRA = 0b00000101;
  	sei(); 
}

void habilitandoPWM(){

	/*
	TCCR0A: 10 10 00 11 
	Modo: Sem prescaler, Non-Inverting Fast PWM, usando as unidades OCRA e OCRB
		
	TCCR0B: 00 00 00 01
	Modo: Sem prescaler

	TIMSK0: 00 00 00 01
	Função: Habilitar interrupções
	*/
	TCCR0A = 0b10100011;
	TCCR0B = 0b00000001;
	TIMSK0 = 0b00000001;
}

int main() {

	selecionandoEntradasESaidas();
	ligandoInterrupcoes();
	habilitandoPWM();

  while(1){
	}
	
	return 0;
}

ISR(INT0_vect) {
	if(!(PIND & (1<<2))){
    OCR0B = 120;
		OCR0A = 120;
	}else{
		OCR0B = 0;
		if(!(PIND & (1<<3))){
			OCR0A = 180;
		}
	}
}

ISR(INT1_vect) {
	if(!(PIND & (1<<3))){
		OCR0A = 120;
		OCR0B = 120;
	}else{
		OCR0A = 0;
		if(!(PIND & (1<<2))){
			OCR0B = 180;
		}
	}
}