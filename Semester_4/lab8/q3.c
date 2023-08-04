#include<LPC17xx.h>
#include "lcdmsh.h"

void scan(void);
unsigned char Msg1[13]="key pressed";
unsigned char row,flag,key;
unsigned long int i,var1,temp,temp1, temp2,temp3;
unsigned char scan_code[16]={0x11,0x21,0x41,0x81,
														0x12,0x22,0x42,0x82,
														0x14,0x24,0x44,0x84,
														0x18,0x28,0x48,0x88};
unsigned char ascii_code[16]={'0','1','2','3',
															'4','5','6','7',
															'8','9','A','B',
															'C','D','E','F'};

int main(void)
{
	LPC_GPIO2->FIODIR |= 0x3c00;
	LPC_GPIO1->FIODIR &= 0xf87fffff;
	LPC_GPIO0->FIODIR |= 0x0F<<23|1<<27|1<<28;
	clear_ports();
	delay_lcd(3000); 
	lcd_init();
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg1[0]);
	while(1)
	{
		while(1)
		{
			for(row=1; row<5; row++)
			{
				if(row==1)
					var1 = 0x400;
				else if(row==2)
					var1 = 0x800;
				else if(row==3)
					var1 = 0x1000;
				else if(row==4)
					var1 = 0x2000;
				
				temp = var1;
				
				LPC_GPIO2->FIOCLR = 0x3C00;
				LPC_GPIO2->FIOSET = var1;
				flag = 0;
				scan();
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		for(i=0; i<16; i++)
		{
			if(key==scan_code[i])
			{
				key = ascii_code[i];
				break;
			}
		}
		temp1 = 0xc0;
		lcd_comdata(temp1,0);
		delay_lcd(800);
		lcd_puts(&key);
	}
	return 0;
}

void scan(void)
{
	temp3 = LPC_GPIO1->FIOPIN;
	temp3 &= 0x07800000;
	if(temp3!=0)
	{
		flag = 1;
		temp3>>=19;
		temp>>=10;
		key = temp3|temp;
	}
}
