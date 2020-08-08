/*
 * 3.c
 *
 * Created: 2/20/2020 11:06:58 AM
 * Author: elnaz
 */

#include <io.h>
#include <delay.h>
#asm
    .EQU __lcd_port = 0x12;portd
#endasm
#include <Lcd.h>

void main(void)
{   
    char key;  
    char ans[6] = "+1234";   
    char temp;
    int i;     
    char flag = 1;   
    DDRB = 0xFF;
    PORTB = 0xF0;
    lcd_init(16);
    _lcd_ready( );
    lcd_clear( ); 
    lcd_gotoxy(0,0);
    for(i=0; i<5; i++)
    {
        key = 0;
        DDRA &= 0x00;
        DDRA |= 0x0F;
        PORTA = 0xF0;
        while(PINA == 0xF0);
        key |= PINA;
        delay_ms(50);
        DDRA &= 0x00;
        DDRA |= 0xF0;
        PORTA = 0x0F;
        key |= PINA;
        switch(key)
        {
            case 0b11101110://7
                lcd_puts("7 ");  
                temp = '7';
                break;
            case 0b11101101://8
                lcd_puts("8 ");  
                temp = '8';
                break;
            case 0b11101011://9
                lcd_puts("9 "); 
                temp = '9';
                break;
            case 0b11100111:// /
                lcd_puts("/ "); 
                temp = '/';
                break;
            case 0b11011110://4
                lcd_puts("4 "); 
                temp = '4';
                break;
            case 0b11011101://5
                lcd_puts("5 ");
                temp = '5';
                break;
            case 0b11011011://6
                lcd_puts("6 ");
                temp = '6';
                break;
            case 0b11010111:// *
                lcd_puts("* ");
                temp = '*';
                break;
            case 0b10111110://1
                lcd_puts("1 ");
                temp = '1';
                break;
            case 0b10111101://2
               lcd_puts("2 ");
               temp = '2';
                break;
            case 0b10111011://3
                lcd_puts("3 ");
                temp = '3';
                break;
            case 0b10110111://-
                lcd_puts("- ");
                temp = '-';
                break;
            case 0b01111110://clear
                lcd_puts("c ");
                temp = 'c';
                break;
            case 0b01111101://0
                lcd_puts("0 ");
                temp = '0';                
                break;
            case 0b01111011:// =
                lcd_puts("= ");
                temp = '=';
                break;
            case 0b01110111:// +
				lcd_puts("+ ");   
                temp = '+';
				break;
		}       
        delay_ms(50);
        if(temp != ans[i]) 
        {
            flag = 0;
        }
	}        
    if(flag == 1)
        PORTB = 255;
    else
        PORTB = 0;
    while(1);
}
