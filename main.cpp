#include <wiringpi.h>
#include "main.h"
#include "Balance.h"
#include "Controls.h"

struct Data{
	float arry[10];
	int count;
};

void add_acc(Data* data, float acc){
	data.arry[(data.count%10)] = acc;
	data.count++;
	if (data.count >= 100000){
		data.count = 0;
	}
}
	

int main()
{
	noecho();//ncurses
	initscr();//ncurses
	timeout(10);//ncurses -- waits 10 ms for input
	int mili_count = millis() + 100;//wiringpi.h -mllis() returns number of milliseconds since program started
	char wasd;
	Balance B;
	Stepper step;
	Data data;
	while(1){
		wasd = getch();
		//add_acc(&data, GYROSCOPE X DATA COMPONENT!!!!!!!!!!!); !!!!!!!!!!!!!!!!
		if(millis() = mili_count){
			mili_count += 100;
			B.move(wasd);
			step.set_steer(B.get_steer());			
		}
	}
	return 0;
}
