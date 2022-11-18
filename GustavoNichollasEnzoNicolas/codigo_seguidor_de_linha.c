/**
*	@file codigo_seguidor_de_linha.ino
*	Projeto de robô com a função de seguir uma linha pertencente a um circuito de automobilismo.
*	Regido pelas disciplinas Programação de Hardware e Dispositivos e Circuitos Eletrônicos
*	**Author:** Enzo Martins Netto Freitas, Gustavo Gouveia Alvarez, Nichollas Leonides de Farias, Nicolas de Jesus Marques 
*/

#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS, BIT) (ADDRESS & (1<<BIT))

/// Declaração da variável responsável pela detecção da cor preta
#define PONTOTRIG 120

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

///Indica o valor analógico recebido pelo sensor esquerdo
volatile uint16_t sensorESQ; 
///Indica o valor analógico recebido pelo sensor direito
volatile uint16_t sensorDIR; 
/// Valores armazenados referente a última iteração do sensor esquerdo
volatile uint16_t valor_previoESQ=0; 
/// Valores armazenados referente a última iteração do sensor direito
volatile uint16_t valor_previoDIR=0;
/// Usada para a prevenção de eventuais saídas da pista de prova 
volatile bool flag=false; 
/// Função que inicia a conversão ADC
uint8_t inicADC(void); 
/// Função que recebe os valores a serem convertidos
uint16_t lerADC(void); 
void configIO();
void configPWM();

int main() 
{	
	inicADC();
	configIO();
	configPWM();
	
	/// O valor 160 atribuído a OCR0A e OCR0B são valores iniciais para os motores
	OCR0A = 160; 
	OCR0B = 160; 
	
	sei();
	
	///Comparações feitas para que o robô se mantenha na linha
	while(1){
		sensorESQ = lerADC(0);
		sensorDIR = lerADC(1);
	 
		if(sensorESQ<PONTOTRIG&&sensorDIR<PONTOTRIG){
		  OCR0A=valor_previoESQ;
		  OCR0B=valor_previoDIR;
		}
		if(sensorESQ>PONTOTRIG&&sensorDIR>PONTOTRIG){
		  OCR0A=160;
		  OCR0B=160;
		} 
		else if(sensorESQ<PONTOTRIG&&sensorDIR>PONTOTRIG){
		  OCR0A=0;
		  valor_previoESQ=0;
		  OCR0B=120; 
		  valor_previoDIR=120;
		}
		else if(sensorESQ>PONTOTRIG&&sensorDIR<PONTOTRIG){
		  OCR0A=120; 
		  valor_previoESQ=120;
		  OCR0B=0;
		  valor_previoDIR=0;
		}
	}
}


/**
*	Função que recebe os valores a serem convertidos
*	@param[in] canal Seleção da porta analógica
*/
uint16_t lerADC(uint8_t canal)
{
  canal &= 0b00000111;
  ADMUX = (ADMUX & 0xF8)|canal;
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  return(ADC);
  ADCSRA |= 0b00010000;
}

/**
*	Função que inicia a conversão ADC
*
*	ADMUX faz a configuração de ARef
*	ADCSRA habilita o ADC e seleciona um prescaler de 128
*/
uint8_t inicADC(void)
{
  ADMUX = (1<<REFS0);
  ADCSRA = 0b10000111;
}

/**
* 	Função responsável pela configuração das entradas e saídas
* 	
*	DDRD -> Configuração das portas: PD2 e PD3 como entrada
*									 PD5 e PD6 como saída
*
*	PD2 e PD3 -> Portas digitais dos sensores esquerdo e direito
*	PD5 e PD6 -> Portas conectadas a base dos transistores relacionadas aos motores esquerdo e direito
*/
void configIO()
{
	CLEARBIT(DDRD,PD2);
	CLEARBIT(DDRD,PD3);
	SETBIT(DDRD,PD5);
	SETBIT(DDRD,PD6);
}

/**
*	Função para a configuração do PWM
*
*	TCCR0A -> Configurado no modo Fast PWM
*			Utilizando OCR0A e OCR0B
*	TCCR0B -> Setado para não utilizar prescaler
*/
void configPWM()
{
	TCCR0A = 0b10100011;
	TCCR0B = 0b00000001;
}