#include "balance.h"

Balance::Balance(){
	desired_angle = 0;
	angle_init = 0;
	angle_acc = 0;
	elapsed_time = 0;
	proportion = 0;
	integral = 0;
	spd = 0;
	calc_spd_count = 0;

	/*
	 *below coefficients are adjusted to control the pi controller
	 */
	p_coeff = 1;
	i_coeff = 1;
}

float Balance::calc_angle(){
	return angle_init + angle_acc/(elapsed_time*elapsed_time);
}

void Balance::calc_spd(){
	//angle_acc = get_angle_acc(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//elapsed_time = get_elapsed_time(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//desired_angle = get_desired_angel(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	calc_spd_count++;
	proportion = calc_angle() - desired_angle; //could need to be calc_angle() + desired_angle;
	integral = elapsed_time*proportion/calc_spd_count;
	spd = p_coeff*proportion + i_coeff*integral;
}

void Balance::move(char wasd){
	switch(wasd){
		case 'w':
		case 'W':
			desired_angle = 2*3.14195* (7 / 8);
			break;
		case 's':
		case 'S':
			desired_angle = -2*3.14195* (7 / 8);
			break;
		case 'a':
		case 'A':
			desired_angle = 0;
			steer.left = 75;
			steer.right = 100;
			break;
		case 'd':
		case 'D':
			desired_angle = 0;
			steer.left = 100;
			steer.right = 75;
			break;
		default:
			desired_angle = 0;
			steer.left = 0;
			steer.right = 0;
			break;
	}
	calc_spd();
	steer.spd = spd;
}

Steer Ballance::get_steer(){
	return steer;
}
