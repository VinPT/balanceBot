#include <wiringpi.h>
#include "main.h"
#include "Balance.h"
#include "Controls.h"


struct Acc_data{
	float acc;
	struct ACC_data* next;
};
class Data_circ_list{
	private:
	struct Acc_data* head;
	public:
	Data_circ_list();
	~Data_circ_list();
	void add_data();
};
int main()
{
	noecho();//ncurses
	initscr();//ncurses
	timeout(10);//ncurses -- waits 10 ms for input
	int mili_count = millis() + 100;//wiringpi.h -mllis() returns number of milliseconds since program started
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
