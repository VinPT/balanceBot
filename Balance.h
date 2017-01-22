
#ifndef BALANCE_H
#define BALANCE_H

struct Steer{
	int right;
	int left;
	float spd;
};

class Balance{
private:
	Steer steer;
	float desired_angle;
	float angle_init;
	float angle_acc;
	float elapsed_time;
	float proportion;
	float integral;
	float p_coeff;
	float i_coeff;
	float spd;
	int calc_spd_count;

	void calc_spd();
	float calc_angle();
public:
	Balance();
	~Balance();
	Steer get_steer();
	void set_angle_acc(float acc){angle_acc = acc;}
	void set_elapsed_time(float time){elapsed_time = time;}
};
#endif
