#ifndef DATA_CIRC_LIST_H
#define DATA_CIRC_LIST_H

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
#endif
