#include "config.h"
#include <xc.h>
 
    
void motorpasso_init (void)
{  
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD4 = 0;
    PORTDbits.RD7 =0;
    PORTDbits.RD6 =0;
    PORTDbits.RD5 =1;
    PORTDbits.RD4 =0;
}

char passo[4] = (0x40, 0x80, 0x10, 0x20);
int passoAtual = 0;

void motorpasso (int numpassos, int t )
{
    
    for ( passoAtual=0; passoAtual<numpassos; passoAtual++ ) 
    {
        PORTD = passo (passoAtual % 4);
        delay(t);
    }
}