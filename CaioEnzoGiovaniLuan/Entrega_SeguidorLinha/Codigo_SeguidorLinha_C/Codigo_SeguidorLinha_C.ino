//Alunos: Caio Monteiro - 188540
        //Luan Carusi de Oliveira - 190245
        //Giovani Martinho - 170707
        //Enzo de Souza Lima - 156503

      
#define f_CPU 16000000

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void InitAdc()  //habilita a conversão de sinal digital para analógico
{
  ADMUX |= (1<<REFS0);
  ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADEN); 
}

uint16_t ReadAdc(uint8_t ADCchanel) //Lê o valor registrado do sinal analogico
{
  ADMUX = (ADMUX & 0xF0) | (ADCchanel & 0x0F);
  ADCSRA |= (1<<ADSC); //Single mode.
  
  while (ADCSRA & (1<<ADSC));
  return ADC;
}

void iniciaMotor(){
  _delay_ms(1500);
  OCR0A = 200;  //Motor Direita
  OCR0B = 200;  //Motor Esquerda
  _delay_ms(100);
}

int main(void){
  
  DDRD |= (1<<PD6); //Define a porta Digital 6 como saída.
  DDRD |= (1<<PD5); //Define a porta Digital 5 como saída.
  
  TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00); 
  TCCR0B |= (1<<CS00);
  
  TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00);
  TCCR0B |= (1<<CS00); 
  
  InitAdc();
  iniciaMotor();  //função que tira o seguidor de linha da inercia
  while(1){

    //Os sensores seguem a  linha preta, quando algum dos lados identificar branco o
    //motor do mesmo lado gira mais rapido para poder corrigir o trajeto
    
    //ReadAdc(0) = Sensor direita
    //ReadAdc(1) = Sensor Esquerda

    if ((ReadAdc(0) >= 500) && (ReadAdc(1) >= 500)) //Sensor direita e Esquerda = Preto
    {
      OCR0A = 170;  
      OCR0B = 170;
    }
    else if ((ReadAdc(0) < 500) && (ReadAdc(1) < 500))  //Sensor direita e Esquerda = Branco
    {
      _delay_ms(800);
      OCR0A = 0;
      OCR0B = 0;
    }
    else if (ReadAdc(0) >= 500) //Sensor Direito = branco | Sensor Esquerdo = preto
    {
      OCR0A = 190;
      OCR0B = 20;
    }
    else if (ReadAdc(1) >= 500) //Sensor Direito = preto | Sensor Esquerdo = branco
    {
      OCR0A = 20;     
      OCR0B = 190;
    }
  }
}
