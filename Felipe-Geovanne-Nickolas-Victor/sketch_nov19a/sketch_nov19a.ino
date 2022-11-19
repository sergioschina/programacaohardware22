//Nomes: Felipe - Geovanne - Nickolas - Victor
//RA:    152799    185335     185823    191068

/*   
    ReadAdc(0) = pinSensorEsq;
    ReadAdc(1) = pinSensorMaisEsq;
    ReadAdc(2) = pinSensorDir;
    ReadAdc(3) = pinSensorMaisDir;

    OCR0A pertence a PD6 (MotorDireita).
    OCR0B pertence a PD5 (MotorEsqueda).
    
    Função InitAdc é responsável por habilitar a conversão de sinal analógico para digital.
    Função ReadAdc é responsável por ler o valor registrado no ADC (analogRead).
    
    O loop sempre efetuará a verificação dos sensores, caso entre em uma das condições
    os motores terão suas rotações PWM alteradas de acordo com cada condição.
*/

#define F_CPU 16400000
#include <stdio.h>
#include <avr/io.h>


#define SETA_BIT(byte, bit) byte |= (1 << bit)
#define ZERA_BIT(byte, bit) byte &= ~(1<<bit)


int valorSensorEsq, valorSensorMaisEsq, valorSensorDir, valorSensorMaisDir;
int velocidadePrincipal = 60;

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

void mudaLed(char statusLed)
{
  switch (statusLed)
  {
    case 0:
      SETA_BIT(PORTD, PD3);
      SETA_BIT(PORTD, PD4);
      break;
    case 1:
      SETA_BIT(PORTD, PD3);
      ZERA_BIT(PORTD, PD4);
      break;
    case 2:
      ZERA_BIT(PORTD, PD3);
      SETA_BIT(PORTD, PD4);
      break;
  }
}

int main(void)
{
  Serial.begin(9640);
  SETA_BIT(DDRD, PD6); //Define a porta D6 como saída.
  SETA_BIT(DDRD, PD5); //Define a porta D5 como saída.
  SETA_BIT(DDRD, PD4); //Define a porta D4 como saída (led direita).
  SETA_BIT(DDRD, PD3); //Define a porta D3 como saída (led esquerda).
  
  OCR0A = 125;  //OCR0A pertence a PD6 (MotorEsquerda).
  OCR0B = 125;  //OCR0B pertence a PD5 (MotorDireita).
  
  TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00); //Non-inverting fast pwm modo 3 Motor Esquerda.
  SETA_BIT(TCCR0B, CS00); //No prescaler.
  
  TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); //Non-inverting fast pwm modo 3 Motor Direita.
  SETA_BIT(TCCR0B, CS00); //No prescaler.
  
  InitAdc();
  while(1)
  {
    /*
    Serial.print("motorEsq: ");
    Serial.println(ReadAdc(0));
    //Serial.print("motorMaisEsq: ");
    //Serial.println(ReadAdc(1));
    //Serial.print("motorDir: ");
    //Serial.println(ReadAdc(2));
    //Serial.print("motorMaisDir: ");
    //Serial.println(ReadAdc(3));
    delay(5000);
    */
    
    if ((ReadAdc(2) <= 500) && (ReadAdc(0) <= 500) && (ReadAdc(3) <= 500) && (ReadAdc(1) <= 500))
    {
      // Anda reto
      OCR0A = 75;  //75 - 95 - 125(max) bom valor
      OCR0B = 75;
      SETA_BIT(PORTD, PD4);
      SETA_BIT(PORTD, PD3);
      mudaLed(0);

    }
    /*
    else if (ReadAdc(0) >= 500 && ReadAdc(1) >= 500)
    {
      // Vira direita
      OCR0A = 255;
      OCR0B = 0;
      SETA_BIT(PORTD, PD4);
      ZERA_BIT(PORTD, PD3);
      mudaLed(1);
      _delay_ms(3000);
    }
    else if (ReadAdc(2) >= 500 && ReadAdc(3) >= 500)
    {
      // Vira esqueda
      OCR0A = 0;
      OCR0B = 255;
      mudaLed(2);
      _delay_ms(3000);
    }*/
    else if (ReadAdc(0) >= 500) //Sensor Esquerdo
    {
      // Vira direita
      OCR0A = 255;
      OCR0B = 0;
      mudaLed(1);
    }
    else if (ReadAdc(2) >= 500) //Sensor Direito
    {
      // Vira esquerda
      OCR0A = 0;     //25 foi bem
      OCR0B = 255;
      mudaLed(2);
    }
    else if (ReadAdc(1) >= 500) //Sensor MaisEsquerdo
    {
      // Vira direita
      OCR0A = 255;
      OCR0B = 0;
      mudaLed(1);
      _delay_ms(640);
    }
    else if (ReadAdc(3) >= 500) //Sensor MaisDireito
    {
      // Vira esqueda
      OCR0A = 0;
      OCR0B = 255;
      mudaLed(2);
      _delay_ms(640);
    }
  }
}
