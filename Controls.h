#ifndef CONTROLS_H
#define CONTROLS_H

class Controls: {
  private:
  char input;
  float move;
  
  void calc_move();
  
  public:
  float get_move();
};

#endif
  
  
