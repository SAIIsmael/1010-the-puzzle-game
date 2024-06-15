#ifndef __SCORE_H
#define __SCORE_H

#include "window.h"
#include <string>
#include <iostream>
#include <fstream>

class Score : public Window{

 private :

  int score;
  std:: string score_str;
  
 public :

  Score(int h, int w, int x, int y, char c = '+');
  
  void print_score();

  void score_to_str();
  
  void add_score(int x);

  void score_save();
  void score_load();

  void best_score(std::string);

};

#endif
