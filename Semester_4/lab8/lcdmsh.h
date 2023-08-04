#include<LPC17xx.h>
#include<stdio.h>
#include "header.c"

void lcd_init(void);
void write(int,int);
void delay_lcd(unsigned int);
void lcd_comdata(int,int);
void clear_ports(void);
void lcd_puts(unsigned char*);