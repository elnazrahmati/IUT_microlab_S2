/*
 * 4.c
 *
 * Created: 2/21/2020 10:52:42 AM
 * Author: elnaz
 */

#include <io.h>
#asm
    .EQU __lcd_port = 0x18;
#endasm
#include <Lcd.h>
#include <delay.h>

int counter = 0;
char string[3];

interrupt [EXT_INT0] void ext_int0_isr(void)
{
	counter++; 
}
interrupt [EXT_INT1] void ext_int1_isr(void)
{
	counter--;
}

void main(void)
{
    lcd_init(16);
    _lcd_ready( );
    lcd_clear( ); 
    lcd_gotoxy(0,0);
    lcd_puts("counter =");//10  
    DDRD = 0;
    PORTD = 255; 
    GICR=0xc0;   //Enable External Interrupts INT0 and INT1
    #asm("sei")
    while (1)
    {
        string[0] = '0' + (counter / 10);
        string[1] = '0' + (counter % 10);
        string[2] = '\0';
        lcd_gotoxy(10,0);
        lcd_puts(string);
        delay_ms(50);
    }
}
