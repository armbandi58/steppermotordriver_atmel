/*
 * test.c
 *
 * Created: 24/06/2021 09:29:10
 * Author : Administrator
 */ 
#include "main.h"

void PORT_init(void);
void full_step_init(void);
void half_step_init(void);
void quarter_step_init(void);
void eighth_step_init(void);
void go_up(void);
void go_down(void);
void timer0_init(void);
void timer1_init(void);
void timer2_init(void);

v8 tmp0 = 32, merre = 0;
bool blink = 0;
u16 stepper_counter = 0;
bool felfuto = 0;
bool token = 0;
u8 count = 0;
vu32 howmanystep = 30000;
vu32 step_rampup = 15000;
vb rampedup = 0;
v8 counter = 6;

int main(void)
{
	PORT_init();
	//full_step_init();
	//half_step_init();
	quarter_step_init();
	//eighth_step_init();
	timer0_init();
	timer2_init();

	u8 in_tmp = 0;

	sei();	
	
	while (1) 
    {
		in_tmp = PINC & 0x06;
		switch(in_tmp){
			case 2:
				//PORTB |= (1<<LED);
				PORTC &= (0<<ENABLE);
				if(!token)
					merre = 1;
			 break;
			case 4:
				//PORTB &= (0<<LED);
				//PORTC &= (0<<ENABLE);
				if(token)
					merre = 4;
			 break;
			default:
				break;
		}
	}
}

/*
ISR(TIMER0_OVF_vect){
	if(!tmp0){
		if(!blink){
			PORTB |= (1<<LED);
			blink = 1;
		}else if(blink){
			PORTB &= (0<<LED);
			blink = 0;
		}
		tmp0 = 32;
	}else{
		tmp0--;
	}
}
*/
/*
ISR(TIMER0_OVF_vect){				
	if(count == counter){
		switch(merre){
			case 1:
			//	PORTC &= (0<<DIR);
			PORTC |= (1<<DIR);
			if(stepper_counter < howmanystep && felfuto){
				PORTB |= (1<<STEP);
				felfuto = 0;
				stepper_counter++;
				}else if(stepper_counter < howmanystep && !felfuto){
				PORTB &= (0<<STEP);
				felfuto = 1;
				stepper_counter++;
			}
			
			if(stepper_counter < 1000){
				counter = 4;
			}else if(stepper_counter < 1500){
				counter = 3;
			}else if(stepper_counter < 2500){
				counter = 2;
			}else if(stepper_counter < 3000){
				counter = 1;
			}else if(stepper_counter > 28000){
				counter = 4;
			}
			
			if (stepper_counter == howmanystep){
				stepper_counter = 0;
				merre = 10;
				token = 1;
				counter = 6;
			}
			break;

			case 4:
			//	PORTC &= (0<<DIR);
			PORTC &= (0<<DIR);
			if(stepper_counter < howmanystep && felfuto){
				PORTB |= (1<<STEP);
				felfuto = 0;
				stepper_counter++;
				}else if(stepper_counter < howmanystep && !felfuto){
				PORTB &= (0<<STEP);
				felfuto = 1;
				stepper_counter++;
			}

			
			if(stepper_counter < 500){
				counter = 4;
				}else if(stepper_counter < 1000){
				counter = 3;
				}else if(stepper_counter < 1500){
				counter = 2;
				}else if(stepper_counter < 2000){
				counter = 1;
				}else if(stepper_counter > 29000){
				counter = 4;
			}

			if (stepper_counter == howmanystep){
				stepper_counter = 0;
				merre = 10;
				token = 0;
			}
			
			
			if (token == 0){
				PORTC |= (1<<ENABLE);
			}
			break;

			default:
			break;
		}
		count = 0;
		}else{
			count += 1;
		}
}
	*/

/*
ISR(TIMER2_COMPA_vect){
	if(!tmp0){
		if(!blink){
			PORTB |= (1<<LED);
			blink = 1;
		}else if(blink){
			PORTB &= (0<<LED);
			blink = 0;
		}
		tmp0 = 32;
	}else{
		tmp0--;
	}
}	
*/

ISR(TIMER2_COMPA_vect){
	if(count == counter){
		switch(merre){
			case 1:
				if(!token){
					//motor forgasirany
					PORTC |= (1<<DIR);
					//PORTC &= (0<<ENABLE);
				
					if(stepper_counter < howmanystep && felfuto){
						PORTB |= (1<<STEP);
						felfuto = 0;
						stepper_counter++;
					}else if(stepper_counter < howmanystep && !felfuto){
						PORTB &= (0<<STEP);
						felfuto = 1;
						stepper_counter++;
					}
			
					if(stepper_counter < 1000){
						counter = 18;
					}else if(stepper_counter < 1200){
						counter = 12;
					}else if(stepper_counter < 1400){
						counter = 8;
					}else if(stepper_counter < 1600){
						counter = 7;
					}else if(stepper_counter < 1800){
						counter = 6;
					}else if(stepper_counter < 2000){
						counter = 5;
					}else if(stepper_counter < 2200){
						counter = 4;
					}else if(stepper_counter > 28000){
						counter = 11;
					}
			
					if (stepper_counter == howmanystep){
						stepper_counter = 0;
						merre = 10;
						token = 1;
						counter = 6;
					}
				}
			break;
					
			case 4:
				if(token){
					//motor forgasirany
					PORTC &= (0<<DIR);
					
					if(stepper_counter < howmanystep && felfuto){
						PORTB |= (1<<STEP);
						felfuto = 0;
						stepper_counter++;
					}else if(stepper_counter < howmanystep && !felfuto){
						PORTB &= (0<<STEP);
						felfuto = 1;
						stepper_counter++;
					}

					if(stepper_counter < 1000){
						counter = 18;
					}else if(stepper_counter < 1200){
						counter = 12;
					}else if(stepper_counter < 1400){
						counter = 8;
					}else if(stepper_counter < 1600){
						counter = 7;
					}else if(stepper_counter < 1800){
						counter = 6;
					}else if(stepper_counter < 2000){
						counter = 5;
					}else if(stepper_counter < 2200){
						counter = 4;
					}else if(stepper_counter > 28000){
						counter = 11;
					}

				if (stepper_counter == howmanystep){
					stepper_counter = 0;
					merre = 10;
					token = 0;
					PORTC |= (1<<ENABLE);
				}
				
				
				if (token == 0){
					PORTC |= (1<<ENABLE);
				}
			}
			 break;

			default:
				break;
		}
		count = 0;
		}else{
		count += 1;
	}	
}


void PORT_init(){
	DDRB |= 0x23;
	DDRC |= 0x01;
	DDRD |= 0x3C;

	PORTB = 0x00; 
	PORTC |= (1<<ENABLE);			
}

void full_step_init(){
	PORTD |= (0<<MS1) | (0<<MS2) | (0<<MS3); 
}

void half_step_init(){
	PORTD |= (1<<MS1) | (0<<MS2) | (0<<MS3);
}

void quarter_step_init(){
	PORTD |= (0<<MS1) | (1<<MS2) | (0<<MS3);
}

void eighth_step_init(){
	PORTD |= (1<<MS1) | (1<<MS2) | (0<<MS3);
}

void go_up(){
	PORTC &= (0<<DIR);
	
	for(u16 i = 4500; i > 0; i--){
		//PORTB ^= 0x01;
		//_delay_ms(1);
		PORTB |= (1<<STEP);
		_delay_us(500);
		PORTB &= (0<<STEP);
		_delay_us(500);
	}	
}

void go_down(){
	PORTC |= (1<<DIR);	
	
	for(u16 i = 4500; i > 0; i--){
		//PORTB ^= 0x01;
		//_delay_ms(1);
		PORTB |= (1<<STEP);
		_delay_us(500);
		PORTB &= (0<<STEP);
		_delay_us(500);
	}
}

void timer0_init(void){
	//nincs eloosztas
	TCCR0A |= (0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
	TCCR0B |= (0<<FOC0A) | (0<<FOC0B) | (0<<WGM02) | (0<<CS02) | (0<<CS01) | (1<<CS00);
	//TCCR0B |= (0<<FOC0A) | (0<<FOC0B) | (0<<WGM02) | (0<<CS02) | (1<<CS01) | (0<<CS00);
	//TIMSK0 |= (0<<OCIE0B) | (0<<OCIE0A) | (1<<TOIE0);
}

void timer2_init(){
	//CTC, 64-es elosztas, 125-ig szamoljon, WGMx1-be 1-es kell, modvalasztas
	//Nincs eloosztas -> CS20 = 1
	//8-as eloosztas -> CS21 = 1
	//1024-es eloosztas -> CS22, CS21, CS20 => 1
	TCCR2A |= (1<<WGM21) | (0<<WGM20);
	TCCR2B |= (0<<WGM22) | (0<<CS22) | (0<<CS21) | (1<<CS20);
	TIMSK2 |= (1<<OCIE2A);
	//OCR0 = 0x0;
	OCR2A = 30;
	//OCR2B = 200; 
//	OCR2B = 124;
}
