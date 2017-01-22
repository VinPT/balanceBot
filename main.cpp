#include <wiringpi.h>
#include "main.h"
#include "Balance.h"
#include "Controls.h"



int main()
{
	noecho();//ncurses
	initscr();//ncurses
	timeout(10);//ncurses -- waits 10 ms for input
	int mili_count = millis() + 100;
	char wasd;
	Balance B;
	Stepper step;
	while(1){
		wasd = getch();
		if(millis() = mili_count){
			mili_count += 100;
			B.move(wasd);
			step.set_steer(B.get_steer());			
		}
	}
	return 0;
}
