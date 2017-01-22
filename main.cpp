
#include "main.h"
#include "Balance.h"
#include "Controls.h"



int main()
{
	noecho();//ncurses
	initscr();//ncurses
	timeout(10);//ncurses -- waits 10 ms for input
	//int mili_count = get_clock() + 100;
	char wasd;
	Balance B;
	while(1){
		wasd = getch();
		if(get_clock() = mili_count){
			B.move(wasd);
		}
	}
	return 0;
}
