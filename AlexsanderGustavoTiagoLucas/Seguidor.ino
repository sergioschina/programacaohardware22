#define F_CPU 16000000

// Macros de Execução
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CHECKBIT(ADDRESS, BIT) (ADDRESS & (1<<BIT))

#include <avr/io.h>
#include <avr/interrupt.h>

#define CLEAR_PWM_VALUE(ENVIROLMENT) (ENVIROLMENT = 0)
#define SET_PWM_VALUE(ENVIROLMENT, VALUE) (ENVIROLMENT = VALUE)

int DEFAULT_PWM_VALUE = 80;
int DRIFT_PWM_VALUE = 100;
int STOP_TIME_MS = 50;

void configureIO(){
	/*
		Configurando portas no pattern:
			PORTD:
				2: Entrada (Sensor)
				3: Entrada (Sensor)
				5: Saída (Motor 1)
				6: Saída (Motor 2)
	*/
	
	// Configurando as entradas;
	CLEARBIT(DDRD, PORTD2);
	CLEARBIT(DDRD, PORTD3);
	
	//Configurando as Saídas;
	SETBIT(DDRD, PORTD5);
	SETBIT(DDRD, PORTD6); 
	
}

void configureInterrupt() {
	
	/* 
		Primariamente iremos configurar/habilitar o INT0 e INT1
		Respectivamente no arduino 
		PD2: INT0 (ATMega, PORTD2) 
		PD3: INT1 (ATMega, PORTD3)
	*/ 

	// Habilitando Interrupções: INT0 e INT 1
	SETBIT(EIMSK, INT0);
	SETBIT(EIMSK, INT1);
	
	/*
		Configurando interrupções no seguinte pattern:
		INT0: 
			Quando houver alteração de nivel lógico: 
				ISC01: 0
				ISC00: 1
		INT1: 
			Quando houver alteração de nivel lógico:
				ISC11: 0
				ISC10: 1
	*/
	
	SETBIT(EICRA, ISC00);
	SETBIT(EICRA, ISC10);
	
	CLEARBIT(EICRA, ISC01);
	CLEARBIT(EICRA, ISC11); 

	//Habilitando interrupções globais
  	sei(); 
}

void configurePWM(){

	/*
		Configurando PWM:
			Configurando TCCR0A:
				Configurações:
					- No Prescaler
					- Non-Inverting Fast PWM
					- Using OCR A Unit
					- Using OCR B Unit
					- Mode 3
				BITS:
					7: COM0A1 (1)
					5: COMOB1 (1)
					1: WGM01 (1)
					0: WGM00 (1)
					
			Configurando TCCR0B:
				Configurações:
					- No Prescaler
				BITS:
					0: CS00 (1)
			
			Configurando TIMSK0:
				Configuração:
					- Habilitando Todos os tipos de interrupção
				BITS:
					0: TOIE0 (1)	
	*/
	
	SETBIT(TCCR0A, COM0A1);
	SETBIT(TCCR0A, COM0B1);
	SETBIT(TCCR0A, WGM01);
	SETBIT(TCCR0A, WGM00);
	SETBIT(TCCR0B, CS00);
	SETBIT(TIMSK0, TOIE0);
}

ISR(INT0_vect) {
	if(!CHECKBIT(PIND, PORTD2)){
    SET_PWM_VALUE(OCR0B, DEFAULT_PWM_VALUE);
    SET_PWM_VALUE(OCR0A, DEFAULT_PWM_VALUE);
	}else{
		CLEAR_PWM_VALUE(OCR0B);
    if(!CHECKBIT(PIND, PORTD3)){
      SET_PWM_VALUE(OCR0A, DRIFT_PWM_VALUE);
      _delay_ms(STOP_TIME_MS);
    }
	}
}

ISR(INT1_vect) {
	if(!CHECKBIT(PIND, PORTD3)){
		SET_PWM_VALUE(OCR0A, DEFAULT_PWM_VALUE);
    SET_PWM_VALUE(OCR0B, DEFAULT_PWM_VALUE);
	}else{
		CLEAR_PWM_VALUE(OCR0A);
    if(!CHECKBIT(PIND, PORTD2)){
      SET_PWM_VALUE(OCR0B, DRIFT_PWM_VALUE);
      _delay_ms(STOP_TIME_MS);
    }
	}
}

int main() {

	configureIO();
	configureInterrupt();
	configurePWM();

  	while(1){
	}
	
	return 0;
}
