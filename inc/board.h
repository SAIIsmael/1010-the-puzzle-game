#ifndef _BOARD_H
#define _BOARD_H

#include "window.h"



const int BOARD_HEIGHT=10;
const int BOARD_WIDTH=10;

class Board : public Window{

 private :

  int shape[5][5];
  int shape_nb;
  int board[BOARD_HEIGHT][BOARD_WIDTH];

  int pos_x;
  int pos_y;
  
 public :

  Board(int h, int w, int x, int y, char c = '+');

  int get_pos_x();
  int get_pos_y();
  int get_shape();

  int get_width();
  int get_height();
  
  void set_shape(int, int[5][5]);
  
  void up();
  void down();
  void left();
  void right();

  void init_board();// initialise le board a 0


  void print_board(); // affiche le board et les pieces qui sont posees

  bool is_empty(int, int, int[5][5]); // verifie si l'emplacement est vide
  bool add_piece(int, int); // si l'emplacement est vide, ajoute la piece

  bool is_placeable(int[5][5]);
  
  int clear_lines(); //supprime les lignes et colonnes pleines, et renvoie le nombre de ligne supprime plus le nombre de colonnes supprimes (pour le score) 

  void board_save();
  void board_load();
};

#endif
