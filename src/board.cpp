#include "board.h"
#include <fstream>
#include <iostream>

Board::Board(int h, int w, int x, int y, char c): Window( h, w, x, y, c){
  for (int i = 0; i < BOARD_WIDTH; i++)
    for (int j = 0; j < BOARD_HEIGHT; j++)
      board[i][j] = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      shape[i][j] = 0;
  
  pos_x = 0;
  pos_y = 0;

  shape[0][0] = 1;

  shape_nb = 0;
}

void Board::set_shape(int x, int s[5][5]){
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      shape[j][i] = s[i][j];

  pos_x = 0;
  pos_y = 0;
  shape_nb = x;
}

int Board::get_pos_x(){
  return pos_x;
}

int Board::get_pos_y(){
  return pos_y;
}

int Board::get_shape(){
  return shape_nb;
}

int Board::get_height(){
  int max_height = 0;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(j > max_height && shape[i][j] != 0)
	max_height = j;
  
  return max_height;
}

int Board::get_width(){
  int max_width = 0;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(j > max_width && shape[j][i] != 0)
	max_width = j;
  
  return max_width;
}

void Board::up(){
  if(pos_y > 0)
    pos_y--;
}

void Board::down(){
  if(pos_y + this->get_height() + 1 < 10)
    pos_y++;
}

void Board::right(){
  if(pos_x + this->get_width() + 1 < 10)
    pos_x++;
}

void Board::left(){
  if(pos_x > 0)
    pos_x--;
}

void Board::init_board(){
 
  for (int i=0;i<10;i++) 
    for (int j=0;j<10;j++) 
      board[i][j] = 0;
}

void Board::print_board(){
  for (int i=0;i<10;i++) // affiche les cases du board
    for (int j=0;j<10;j++){ 
      if(board[i][j] == 1)
	this->Window::print(i, j, ' ', BWHITE);
      if(board[i][j] == 2)
	this->Window::print(i, j, ' ', WBLUE);
      if(board[i][j] == 3)
	this->Window::print(i, j, ' ' , BGREEN);
      if(board[i][j] == 4)
	this->Window::print(i, j, ' ', BYELLOW);
      if(board[i][j] == 5)
	this->Window::print(i, j, ' ', WRED);
    }

  for(int i = 0; i < 5; i++){ // affiche la current_piece
    for(int j = 0; j < 5; j++){
      if(is_empty(pos_x, pos_y, shape)){
	if(shape[i][j] == 1)
	  this->Window::print(i+pos_x, j+pos_y, ' ', BWHITE);
	if(shape[i][j] == 2)
	  this->Window::print(i+pos_x, j+pos_y, ' ', WBLUE);
	if(shape[i][j] == 3)
	  this->Window::print(i+pos_x, j+pos_y, ' ', BGREEN);
	if(shape[i][j] == 4)
	  this->Window::print(i+pos_x, j+pos_y, ' ', BYELLOW);
	if(shape[i][j] == 5)
	  this->Window::print(i+pos_x, j+pos_y, ' ', WRED);
      
      } else {
	if(shape[i][j] != 0)
	  this->Window::print(i+pos_x, j+pos_y, ' ', WMAGENTA);
      }
    }
  }
}

bool Board::is_empty(int posx, int posy, int p[5][5]){
  bool valid = true;
  
  for (int i=0;i<5;i++) 
    for (int j=0;j<5;j++) {
      if(p[i][j] != 0)
	if(board[i+posx][j+posy] != 0)
	  valid=false;
    }

  return valid;
}


bool Board::add_piece(int posx, int posy){
  bool res = is_empty(posx, posy, shape);
  if(is_empty(posx, posy, shape)){
    for (int i=0;i<5;i++) 
      for (int j=0;j<5;j++) 
	if(shape[i][j] != 0)
	  board[i+posx][j+posy] = shape[i][j];
  }
  pos_x = 0;
  pos_y = 0;

  return res;
}


int Board::clear_lines(){
  int score = 0;
  
  int lines_full[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int columns_full[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  bool line_full = true;
  bool column_full = true;

  // remplis un tableau avec un 1 pour chaque ligne ou colonne pleine
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if(board[i][j] == 0)
	line_full = false;
      if(board[j][i] == 0)
      	column_full = false;
    }
    if(line_full){
      lines_full[i] = 1;
      score++;
    }
    else
      line_full = true;
    if(column_full){
      columns_full[i] = 1;
      score++;
    }
    else
      column_full = true;
  }

  //supprime les lignes et colonnes vides
  for(int i = 0; i < 10; i++){
    if(lines_full[i] == 1){
      for(int j = 0; j < 10; j++)
	board[i][j] = 0;
      //score ++;
    }
    if(columns_full[i] == 1){
      for(int j = 0; j < 10; j++)
	board[j][i] = 0;
      //score ++;
    }
  }

  return score;
}

bool Board::is_placeable(int p[5][5]){
  int max_height = 0;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(j > max_height && p[i][j] != 0)
	max_height = j;

  int max_width = 0;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(j > max_width && p[j][i] != 0)
	max_width = j;

  bool placeable = false;
  
  for(int i = 0; i < (10 - max_height); i++)
    for(int j = 0; j < (10 - max_width); j++)
      if(is_empty(j, i, p))
	placeable = true;
	
  return placeable;
}

void Board::board_save(){
  std::string name = "save";
  std::ofstream file(name.c_str(), std::ios::out);
  if(file){
    for(int i = 0; i < 10; i++)
      for(int j = 0; j < 10; j++)
	file << board[i][j];
    file.close();
  }
}


void Board::board_load(){
  char c;
  std::string name = "save";
  std::ifstream file(name.c_str(), std::ios::in);
  if(file){
    for(int i = 0; i < 10; i++)
      for(int j = 0; j < 10; j++){
	file.get(c);
	if(c == '0')
	  board[i][j] = 0;
	if(c == '1')
	  board[i][j] = 1;
	if(c == '2')
	  board[i][j] = 2;
	if(c == '3')
	  board[i][j] = 3;
	if(c == '4')
	  board[i][j] = 4;
	if(c == '5')
	  board[i][j] = 5;
      }
  }
}
