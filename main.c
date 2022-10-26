#include <msp430.h> 


void delay(){

   volatile unsigned long int i;

   i = 14000;                          // SW Delay

   while(i != 0){
       i--;
   }
}

void clean() {
    P1OUT &= ~BIT5;      //1
    P1OUT &= ~BIT6;      //2
    P1OUT &= ~BIT7;      //3
    P3OUT &= ~BIT6;      //4
    P5OUT &= ~BIT2;      //5
    P4OUT &= ~BIT5;      //6
}
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer


	PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
	                                            // to activate previously configured port settings
	P1DIR |= BIT5;      //1                    // Set P1.0 to output direction
	P1DIR |= BIT6;      //2
	P1DIR |= BIT7;      //3
	P3DIR |= BIT6;      //4
	P5DIR |= BIT2;      //5
	P4DIR |= BIT5;      //6

	volatile int q = 0;

	while(1){

	P1OUT ^= BIT0;      // Toggle P1.0 using exclusive-OR
	clean();
	q = 0;
	    while (q < 2){     //Goofy alternating lights (quite clamplicated)
	        P1OUT ^= BIT5; //
	        delay();
	        P1OUT ^= BIT5; //
	        P1OUT ^= BIT7; //
	        delay();
	        P1OUT ^= BIT7; //
	        P1OUT ^= BIT6; //
	        delay();
	        P1OUT ^= BIT6; //
	        P3OUT ^= BIT6; //
	        delay();
	        P3OUT ^= BIT6; //
	        P1OUT ^= BIT7; //
	        delay();
	        P1OUT ^= BIT7; //
	        P5OUT ^= BIT2; //
	        delay();
	        P5OUT ^= BIT2; //
	        P3OUT ^= BIT6;
	        delay();
	        P3OUT ^= BIT6;
	        P4OUT ^= BIT5;
	        delay();
	        P4OUT ^= BIT5;
	        q++;
	    }

	    clean();
	    q = 0;
	    while (q < 2){  //Rising & Falling lights? (Shrimple)
	        P4OUT ^= BIT5;
	        delay();
	        P5OUT ^= BIT2;
	        delay();
	        P3OUT ^= BIT6;
	        delay();
	        P1OUT ^= BIT7;
	        delay();
	        P1OUT ^= BIT6;
	        delay();
	        P1OUT ^= BIT5;
	        delay();
	        P1OUT ^= BIT5;
	        delay();
	        P1OUT ^= BIT6;
	        delay();
	        P1OUT ^= BIT7;
	        delay();
	        P3OUT ^= BIT6;
	        delay();
	        P5OUT ^= BIT2;
	        delay();
	        P4OUT ^= BIT5;
	        q++;
	    }

	    clean();
	    q = 0;
	    while (q < 6){      //Alternating flash (Shrimple)
	        P1OUT ^= BIT5;
	        P1OUT ^= BIT7;
	        P5OUT ^= BIT2;
	        delay();
	        P3OUT ^= BIT6;
	        P5OUT ^= BIT2;
	        P4OUT ^= BIT5;
	        P1OUT ^= BIT5;
	        P1OUT ^= BIT6;
	        P1OUT ^= BIT7;
	        delay();
	        P1OUT ^= BIT6;
	        P3OUT ^= BIT6;
	        P4OUT ^= BIT5;
	        q++;
	    }
	    clean();
	    q = 0;
	    while (q < 2){      //Chasing Lights (Shrimple)
	        P1OUT ^= BIT5;
	        delay();
	        P1OUT ^= BIT5;
	        P1OUT ^= BIT6;
	        delay();
	        P1OUT ^= BIT6;
	        P1OUT ^= BIT7;
	        delay();
	        P1OUT ^= BIT7;
	        P3OUT ^= BIT6;
	        delay();
	        P3OUT ^= BIT6;
	        P5OUT ^= BIT2;
	        delay();
	        P5OUT ^= BIT2;
	        P4OUT ^= BIT5;
	        delay();
	        P4OUT ^= BIT5;
	        P5OUT ^= BIT2;
	        delay();
	        P5OUT ^= BIT2;
	        P3OUT ^= BIT6;
	        delay();
	        P3OUT ^= BIT6;
	        P1OUT ^= BIT7;
	        delay();
	        P1OUT ^= BIT7;
	        P1OUT ^= BIT6;
	        delay();
	        P1OUT ^= BIT6;
	        q++;
	    }


	 }

	
	return 0;
}
