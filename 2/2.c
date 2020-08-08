/*
 * 2.c
 *
 * Created: 2/20/2020 10:20:51 AM
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
    lcd_init(16);
    _lcd_ready( );
    lcd_clear( ); 
    lcd_gotoxy(0,0);
    while(1)
    {
        key = 0;
        DDRA &= 0x00;
        DDRA |= 0x0F;
        PORTA = 0xF0;
        while(PINA == 0xF0);
        key |= PINA;
        delay_ms(100);
        DDRA &= 0x00;
        DDRA |= 0xF0;
        PORTA = 0x0F;
        key |= PINA;
        switch(key)
        {
            case 0b11101110://7
                lcd_puts("7 ");
                break;
            case 0b11101101://8
                lcd_puts("8 ");
                break;
            case 0b11101011://9
                lcd_puts("9 ");
                break;
            case 0b11100111:// /
                lcd_puts("/ ");
                break;
            case 0b11011110://4
                lcd_puts("4 ");
                break;
            case 0b11011101://5
                lcd_puts("5 ");
                break;
            case 0b11011011://6
                lcd_puts("6 ");
                break;
            case 0b11010111:// *
                lcd_puts("* ");
                break;
            case 0b10111110://1
                lcd_puts("1 ");
                break;
            case 0b10111101://2
               lcd_puts("2 ");
                break;
            case 0b10111011://3
                lcd_puts("3 ");
                break;
            case 0b10110111://-
                lcd_puts("- ");
                break;
            case 0b01111110://clear
                lcd_puts("c ");
                break;
            case 0b01111101://0
                lcd_puts("0 ");
                break;
            case 0b01111011:// =
                lcd_puts("= ");
                break;
            case 0b01110111:// +
				lcd_puts("+ ");
				break;
		}
	}
}
