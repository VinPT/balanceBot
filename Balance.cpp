#include "balance.h"

Balance::Balance(){
	angle_init = 0;
	angle_acc = 0;
	elapsed_time = 0;
	proportion = 0;
	integral = 0;
	spd = 0;

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
	proportion = calc_angle();
	integral = elapsed_time*proportion;
	spd = p_coeff*proportion + i_coeff*integral;
}

float Balance::get_spd(){
	calc_spd();
	return spd;
}
