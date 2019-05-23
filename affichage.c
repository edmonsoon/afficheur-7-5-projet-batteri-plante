#include <avr/io.h> //E∕S ex PORTB
#define F_CPU 16000000UL
#include <util/delay.h>

unsigned short cap;

void affiche(int);

unsigned short adc_read(uint8_t ch){
ch &= 0x07;
ADMUX=(ADMUX & 0xF8)|ch;// on reserver les bit du repertoire ADMUX pour les conversion an/num de ch
ADCSRA |= (1<<ADSC); // commencer la conversion
while(ADCSRA & (1<<ADSC));// attentre la fin  de la convertion
  return (ADC);
}

void adc_init(void){
  DIDR0=0xff;//
  ADMUX = (1<<REFS0); //ADMUX c'est un repertoire qui contient REFS0 qui met le max a 5v si REFS0 et REFS1 =1 le max est de 2.5v
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);// je ne comprend pas cette ligne

}


int main(void){

        //ligne
        DDRD |=1<<PORTD0; //d3
        DDRD |=1<<PORTD1; //d2
        DDRD |=1<<PORTD2; //d0
        DDRD |=1<<PORTD3; //d1
        DDRD |=1<<PORTD4; //d4

        //colone

        DDRC |=1<<PORTC6; //d5
        DDRD |=1<<PORTD7; //d6
        DDRE |=1<<PORTE6; //d7
        DDRB |=1<<PORTB4; //d8
        DDRB |=1<<PORTB5; //d9
        DDRB |=1<<PORTB6; //d10
        DDRB |=1<<PORTB7; //d11
        //but du projet faire une sorte d'indicteur de batterie mais pour l'humidter d'une plante
          //voir planche projet
adc_init();


        while(1){

cap=adc_read(0);
int rep=0;



if(cap>900){
affiche(1); //0%
}
if(750<=cap && cap<=900){
affiche(2);//20%
}
if(600<=cap && cap<750){
affiche(3);//40%
}
if(450<=cap && cap<600){
affiche(4);//60%
}
if(300<=cap && cap<450){
affiche(5);//80%
rep=0;
}
if(250<=cap && cap<300 && rep==0){
affiche(6);//100%
}
if(cap<250 && rep==0){
  affiche(7);//caution
  rep=1;
  }
if(cap<250 && rep==1){
    affiche(6);//caution

    }

}
  return 0;
                }




void affiche(int r){

int o=0;
if(r==1){
	//affiche 0
  while (o<=50){
  _delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);

PORTC&=~(1<<PORTC6);
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);
_delay_ms(2);
o=o+1;
}
	}
if(r==2){
	 //affiche20
while (o<=50){
_delay_ms(2);

PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);
_delay_ms(2);

o=o+1;
}
	}

	if(r==3){
		//affiche40
while (o<=50){
_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);
_delay_ms(2);
o=o+1;
}
	}
if(r==4){
while (o<=50){
//affiche60
_delay_ms(2);

PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);

_delay_ms(2);
o=o+1;
}
}

if(r==5){
//affiche80
while (o<=50){
_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);
_delay_ms(2);
o=o+1;
}
}

if(r==6){
//affiche100
while (o<=50){
_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;
_delay_ms(2);
o=o+1;
}
	}

	if(r==7){
int t=0;
while(t<=6){
//affiche100
while (o<=50){
_delay_ms(2);
PORTD&=~(1<<PORTD2);
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD&=~(1<<PORTD4);

PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD&=~(1<<PORTD1);
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;

PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;
_delay_ms(2);
o=o+1;
}
	//

	//
o=0;
while (o<=50){
		//caution (grand triandle)
_delay_ms(2);
PORTD&=~(1<<PORTD2); //pour l'etat 0
PORTD|=1<<PORTD3;    //pour l'etat 1
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD|=1<<PORTD4;
                     //l1   1111111
PORTC|=1<<PORTC6;
PORTD|=1<<PORTD7;
PORTE|=1<<PORTE6;
PORTB|=1<<PORTB4;
PORTB|=1<<PORTB5;
PORTB|=1<<PORTB6;
PORTB|=1<<PORTB7;
_delay_ms(2);

PORTD|=1<<PORTD2;
PORTD&=~(1<<PORTD3);
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD|=1<<PORTD4;
					//l2   1000001
PORTC|=1<<PORTC6;
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB|=1<<PORTB7;

_delay_ms(2);

PORTD|=1<<PORTD2;
PORTD|=1<<PORTD3;
PORTD&=~(1<<PORTD1);
PORTD|=1<<PORTD0;
PORTD|=1<<PORTD4;
					//l3  0100010
PORTC&=~(1<<PORTC6);
PORTD|=1<<PORTD7;
PORTE&=~(1<<PORTE6);
PORTB&=~(1<<PORTB4);
PORTB&=~(1<<PORTB5);
PORTB|=1<<PORTB6;
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD&=~(1<<PORTD0);
PORTD|=1<<PORTD4;
					//l4  0010100
PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE|=1<<PORTE6;
PORTB&=~(1<<PORTB4);
PORTB|=1<<PORTB5;
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);

_delay_ms(2);
PORTD|=1<<PORTD2;
PORTD|=1<<PORTD3;
PORTD|=1<<PORTD1;
PORTD|=1<<PORTD0;
PORTD&=~(1<<PORTD4);
					//l5  0001000
PORTC&=~(1<<PORTC6);
PORTD&=~(1<<PORTD7);
PORTE&=~(1<<PORTE6);
PORTB|=1<<PORTB4;
PORTB&=~(1<<PORTB5);
PORTB&=~(1<<PORTB6);
PORTB&=~(1<<PORTB7);
_delay_ms(2);

o=o+1;
}

t=t+1;
o=0;

}

		}

}
