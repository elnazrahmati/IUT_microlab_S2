/*
 * 1.c
 *
 * Created: 2/20/2020 9:04:09 AM
 * Author: elnaz
 */

#include <io.h>
#asm
    .EQU __lcd_port = 0x12;portd
#endasm
#include <Lcd.h>
              
void main(void)
{   
    lcd_init(16);
    _lcd_ready( );
    lcd_clear( ); 
    lcd_gotoxy(0,0);
    lcd_puts("Elnaz Rahmati");
    lcd_gotoxy(0,1);
    lcd_puts("9628153");

while (1)
    {
    }
}
