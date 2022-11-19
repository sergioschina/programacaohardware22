//Nome: Isabelle Mosca Rizzardo - RA: 185887
//      Odara Fernanda dos Santos Toledo - RA: 185405

//Observações:

//OCR0A pertence a PD6 (MotorEsquerda).
//OCR0B pertence a PD5 (MotorDireita).

//ReadAdc(0) = SensorDireita;
//ReadAdc(1) = SensorEsquerda;

//Função InitAdc é responsável por habilitar a conversão de sinal analógico para digital.
//Função ReadAdc é responsável por ler o valor registrado no ADC.

//O loop sempre efetuará a verificação dos sensores, caso entre em uma das condições
//os motores terão suas rotações PWM alteradas de acordo com cada condição.

#define F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>

void InitAdc()
{
ADMUX |= (1<<REFS0);
ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADEN); //Habilitando o ADC e definindo prescaler para 128.
}

uint16_t ReadAdc(uint8_t ADCchanel)
{
ADMUX = (ADMUX & 0xF0) | (ADCchanel & 0x0F);
ADCSRA |= (1<<ADSC); //Single mode.

while (ADCSRA & (1<<ADSC));

return ADC;
}

int main(void)
{
  
DDRD |= (1<<PD6); //Define a porta D6 como saída.
DDRD |= (1<<PD5); //Define a porta D5 como saída.

ReadAdc(0);
ReadAdc(1);

OCR0A = 204; //Define o ciclo de operação.
OCR0B = 204; //Define o ciclo de operação.

TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00); //Non-inverting fast pwm modo 3 Motor Esquerda.
TCCR0B |= (1<<CS00); //No prescaler.

TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); //Non-inverting fast pwm modo 3 Motor Direita.
TCCR0B |= (1<<CS00); //No prescaler.

InitAdc();

while(1)
{
if ((ReadAdc(0)  <= 500) && (ReadAdc(1) <= 500))
{
OCR0A = 200;
OCR0B = 200;

}

else if ((ReadAdc(0) <= 500) && (ReadAdc(1) >= 100))
{
OCR0A = 235;
OCR0B = 0;

}

else if ((ReadAdc(0) > 100) && (ReadAdc(1) < 700))
{
OCR0A = 0;
OCR0B = 235;

}

}
}
