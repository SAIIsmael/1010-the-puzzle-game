#ifndef __CHOICE_H
#define __CHOICE_H

#include "window.h"
#include <fstream>
#include <iostream>

class Choice : public Window{

 private :

  //tableau regroupant les formes
  int shapes[14][5][5];

  //piece actuelle
  int nb_shape;
  
  // tableaux des formes
  int shape1[5][5];
  int shape2[5][5];
  int shape3[5][5];

  // correspondance des formes au tableau de base
  int shape1_nb;
  int shape2_nb;
  int shape3_nb;
  
 public :

  Choice(int h, int w, int x, int y, int shapes1[14][5][5], int rand, char c = '+');
    
  int get_shape(int);
  int get_shape2(int);
  
  int get_width(int); // pour centrer la piece dans l'affichage
  int get_height(int);

  void set_choice(int, int, int); // remplie les 3 choix aleatoires avec set_shape

  bool del_shape(); // supprime la piece des choix; retourne true si au moins un choix est toujours possible
  
  void print_choice();
  
  void choice_save();
  void choice_load();
};

#endif
