#ifndef BALANCE_H
#define BALANCE_H

class Balance{
private:
	float angle_init;
	float angle_acc;
	float elapsed_time;
	float proportion;
	float intagral;
	float p_coeff;
	float i_coeff;
	float spd;


	float calc_spd();
	float calc_angle();
public:
	Balance();
	~Balance();
	float get_spd();
};
#endif
