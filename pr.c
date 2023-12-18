/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/14/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <delay.h>

// Declare your global variables here

void main(void)
{
int sec=0, min=0, hour=12,dly;
	int seg1,seg2,seg3,seg4,seg5,seg6;
	int seg[]={0x3f,0x06, 0x5b,0x4f,0x66,0x6d, 0x7d,0x07,0x7f,0x6f};
	int flag=0;
	DDRC=0xff;
	DDRD=0xff;
	PORTB=0X0f;
while (1)
      {
     for(sec=0;sec<60;sec++)
		{
			seg2=hour%10;
			seg1=hour/10;

			seg4=min%10;
			seg3=min/10;

			seg6=sec%10;
			seg5=sec/10;
			for(dly=0;dly<25;dly++)
			{  


            if((PINB&0X01)==0x00)
				{
					while((PINB&0X01)==0X00);
					flag=flag+1;
				}


				while(flag==1)
				{
					if((PINB&0x02)==0x00)
					{
						while((PINB&0X02)==0X00);
						hour=hour+1;
					}

					if((PINB&0x04)==0x00)
					{
						while((PINB&0X04)==0X00);
						hour=hour-1;
					}

					if(hour==13)
						hour=1;
					if(hour==0)
				        hour=12;

                    seg2=hour%10;
                    seg1=hour/10;

                    PORTD=0xfe;
                    PORTC=seg[seg1];
                    delay_ms(10);

                    PORTD=0xfd;
                    PORTC=seg[seg2];
                    delay_ms(10);

                    if((PINB&0X01)==0x00)
                    {
                        while((PINB&0X01)==0X00);
                        flag=flag+1;
                    }
                }

                
                while(flag==2)
                {
                    if((PINB&0x02)==0x00)
                    {
                        while((PINB&0X02)==0X00);
                        min=min+1;
                    }

                    if((PINB&0x04)==0x00)
                    {
                        while((PINB&0X04)==0X00);
                        min=min-1;
                    }

                    if(min==60)
                        min=0;
                    if(min==-1)
                        min=59;

                    seg4=min%10;
                    seg3=min/10;

                    PORTD=0xfb;
                    PORTC=seg[seg3];
                    delay_ms(5);

                    PORTD=0xf7;
                    PORTC=seg[seg4];
                    delay_ms(5);

                    if((PINB&0X01)==0x00)
                    {
                        while((PINB&0X01)==0X00);
                        flag=flag+1;
                    }
                }

                while(flag==3)
                {
                    if((PINB&0x02)==0x00)
                    {
                        while((PINB&0X02)==0X00);
                        sec=sec+1;
					}

					if((PINB&0x04)==0x00)
					{
						while((PINB&0X04)==0X00);
						sec=sec-1;
					}

					if(sec==60)
						sec=0;
					if(sec==-1)
						sec=59;

					seg6=sec%10;
					seg5=sec/10;

					PORTD=0xef;
					PORTC=seg[seg5];
					delay_ms(5);

					PORTD=0xdf;
					PORTC=seg[seg6];
					delay_ms(5);

					if((PINB&0X01)==0x00)
					{
						while((PINB&0X01)==0X00);
						flag=0;
					}
				}

	
				PORTD=0xfe;
				PORTC=seg[seg1];
				delay_ms(5);

				PORTD=0xfd;
				PORTC=seg[seg2];
				delay_ms(10);

				PORTD=0xfb;
				PORTC=seg[seg3];
				delay_ms(5);

				PORTD=0xf7;
				PORTC=seg[seg4];
				delay_ms(5);

				PORTD=0xef;
				PORTC=seg[seg5];
				delay_ms(5);

				PORTD=0xdf;
				PORTC=seg[seg6];
				delay_ms(10);
			}
		}
		min=min++;
		if(min==60)
		{
			hour++;
			min=0;
		}	
		if(hour==13)
		{
			hour=1;	
		}

      }
}
