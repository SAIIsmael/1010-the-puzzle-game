#include "choice.h"

Choice::Choice(int h, int w, int x, int y, int shapes1[14][5][5], int rand, char c): Window (h, w, x, y, c){
  
  for (int i = 0; i < 14; i++)
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++)
	      shapes[i][j][k] = shapes1[i][j][k];
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      shape1[i][j] = shapes[rand%14][i][j];
      shape2[i][j] = shapes[(rand+5)%14][i][j];
      shape3[i][j] = shapes[(rand+10)%14][i][j];
    }
  shape1_nb = rand % 14;
  shape2_nb = (rand + 5) % 14;
  shape3_nb = (rand + 10) % 14;
}

void Choice::print_choice(){

  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      if(shape1[j][i] == 1)
	this->Window::print(i+1+this->Choice::get_width(1), j+1+this->Choice::get_height(1), ' ', BWHITE);
      else if(shape1[j][i] == 2)
	this->Window::print(i+1+this->Choice::get_width(1), j+1+this->Choice::get_height(1), ' ', WBLUE);
      else if(shape1[j][i] == 3)
	this->Window::print(i+1+this->Choice::get_width(1), j+1+this->Choice::get_height(1), ' ', BGREEN);
      else if(shape1[j][i] == 4)
	this->Window::print(i+1+this->Choice::get_width(1), j+1+this->Choice::get_height(1), ' ', BYELLOW);
      else if(shape1[j][i] == 5)
	this->Window::print(i+1+this->Choice::get_width(1), j+1+this->Choice::get_height(1), ' ', WRED);

      if(shape2[j][i] == 1)
	this->Window::print(i+1+this->Choice::get_width(2), j+7+this->Choice::get_height(2), ' ', BWHITE);
      else if(shape2[j][i] == 2)
	this->Window::print(i+1+this->Choice::get_width(2), j+7+this->Choice::get_height(2), ' ', WBLUE);
      else if(shape2[j][i] == 3)
	this->Window::print(i+1+this->Choice::get_width(2), j+7+this->Choice::get_height(2), ' ', BGREEN);
      else if(shape2[j][i] == 4)
	this->Window::print(i+1+this->Choice::get_width(2), j+7+this->Choice::get_height(2), ' ', BYELLOW);
      else if(shape2[j][i] == 5)
	this->Window::print(i+1+this->Choice::get_width(2), j+7+this->Choice::get_height(2), ' ', WRED);

      if(shape3[j][i] == 1)
	this->Window::print(i+1+this->Choice::get_width(3), j+13+this->Choice::get_height(3), ' ', BWHITE);
      else if(shape3[j][i] == 2)
	this->Window::print(i+1+this->Choice::get_width(3), j+13+this->Choice::get_height(3), ' ', WBLUE);
      else if(shape3[j][i] == 3)
	this->Window::print(i+1+this->Choice::get_width(3), j+13+this->Choice::get_height(3), ' ', BGREEN);
      else if(shape3[j][i] == 4)
	this->Window::print(i+1+this->Choice::get_width(3), j+13+this->Choice::get_height(3), ' ', BYELLOW);
      else if(shape3[j][i] == 5)
	this->Window::print(i+1+this->Choice::get_width(3), j+13+this->Choice::get_height(3), ' ', WRED);
    }

}


void Choice::set_choice(int rand1, int rand2, int rand3){

  rand1 = rand1%14;
  rand2 = rand2%14;
  rand3 = rand3%14;
  
  if(rand1 == rand2)
    rand2 += 5;
  if(rand1 == rand3)
    rand3 += 5;
  if(rand2 == rand3)
    rand3 += 5;
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      shape1[i][j] = shapes[rand1%14][i][j];
      shape2[i][j] = shapes[rand2%14][i][j];
      shape3[i][j] = shapes[rand3%14][i][j];
    }
  
  shape1_nb = rand1 % 14;
  shape2_nb = rand2 % 14;
  shape3_nb = rand3 % 14;
}

int Choice::get_shape(int x){
  if(x == 1){
    if(shape1_nb != -1){
      nb_shape = 1;
      return shape1_nb;
    } else if(shape2_nb != -1){
      nb_shape = 2;
      return shape2_nb;
    } else {
      nb_shape = 3;
      return shape3_nb;
    }
  } else if(x == 2){
    
    if(shape2_nb != -1){
      nb_shape = 2;
      return shape2_nb;
    } else if(shape1_nb != -1){
      nb_shape = 1;
      return shape1_nb;
    } else {
      nb_shape = 3;
      return shape3_nb;
    }
  } else if(x == 3){
    
    if(shape3_nb != -1){
      nb_shape = 3;
      return shape3_nb;
    } else if(shape1_nb != -1){
      nb_shape = 1;
      return shape1_nb;
    } else {
      nb_shape = 2;
      return shape2_nb;
    }
  }
  else
    return 42;
}

int Choice::get_shape2(int x){
  if(x == 1)
    return shape1_nb;
  else if(x == 2)
    return shape2_nb;
  else
    return shape3_nb;
}

bool Choice::del_shape(){
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      if(nb_shape == 1)
	shape1[i][j] = 0;
      if(nb_shape == 2)
	shape2[i][j] = 0;
      if(nb_shape == 3)
	shape3[i][j] = 0;
    }

  if(nb_shape == 1)
        shape1_nb = -1;
  if(nb_shape == 2)
	shape2_nb = -1;
  if(nb_shape == 3)
	shape3_nb = -1;


  if(shape1_nb == -1 && shape2_nb == -1 && shape3_nb == -1){
    return true;
  } else
    return false;
}

int Choice::get_width(int x){
  
  int max_width = 0;
  if(x == 1){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_width && shape1[i][j] != 0)
	  max_width = j;
  } else if(x == 2){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_width && shape2[i][j] != 0)
	  max_width = j;
  } else if(x == 3){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_width && shape3[i][j] != 0)
	  max_width = j;
  }
  return (5 - max_width) / 2;
}

int Choice::get_height(int x){
  int max_height = 0;

  if(x == 1){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_height && shape1[j][i] != 0)
	  max_height = j;
  } else if(x == 2){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_height && shape2[j][i] != 0)
	  max_height = j;
  } else if(x == 3){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
	if(j > max_height && shape3[j][i] != 0)
	  max_height = j;
  }
  
  return (5 - max_height) / 2;
}

void Choice::choice_save(){
  std::string name = "save";
  std::ofstream file(name.c_str(), std::ios::app);
  if(file){
    if(shape1_nb < 10 && shape1_nb != -1)
      file << 0;
    file << shape1_nb;
    
    if(shape2_nb < 10 && shape2_nb != -1)
      file << 0;
    file << shape2_nb;

    if(shape3_nb < 10 && shape3_nb != -1)
      file << 0;
    file << shape3_nb;
    file.close();
  }
}

void Choice::choice_load(){
  char c;
  int s1 = 0, s2 = 0, s3 = 0;
  std::string name = "save";
  std::ifstream file(name.c_str(), std::ios::in);

  if(file){
    for(int i = 0; i < 101; i++)
      file.get(c);

    //forme 1
    
    if(c == '1')
      s1 += 10;
    else  if(c == '-'){
      s1 = -1;
      file.get(c);
    } else{
      file.get(c);
      if(     c == '1')
	s1 += 1;
      else if(c == '2')
	s1 += 2;
      else if(c == '3')
	s1 += 3;
      else if(c == '4')
	s1 += 4;
      else if(c == '5')
	s1 += 5;
      else if(c == '6')
	s1 += 6;
      else if(c == '7')
	s1 += 7;
      else if(c == '8')
	s1 += 8;
      else if(c == '9')
	s1 += 9;
    }

    file.get(c);
  
    //forme 2

    if(c == '1')
      s2 += 10;
    else  if(c == '-'){
      s2 = -1;
      file.get(c);
    } else{
      file.get(c);
      if(     c == '1')
	s2 += 1;
      else if(c == '2')
	s2 += 2;
      else if(c == '3')
	s2 += 3;
      else if(c == '4')
	s2 += 4;
      else if(c == '5')
	s2 += 5;
      else if(c == '6')
	s2 += 6;
      else if(c == '7')
	s2 += 7;
      else if(c == '8')
	s2 += 8;
      else if(c == '9')
	s2 += 9;
    }

    file.get(c);
  
    //forme 3

    if(c == '1')
      s3 += 10;
    else  if(c == '-'){
      s3 = -1;
      file.get(c);
    } else{
      file.get(c);
      if(     c == '1')
	s3 += 1;
      else if(c == '2')
	s3 += 2;
      else if(c == '3')
	s3 += 3;
      else if(c == '4')
	s3 += 4;
      else if(c == '5')
	s3 += 5;
      else if(c == '6')
	s3 += 6;
      else if(c == '7')
	s3 += 7;
      else if(c == '8')
	s3 += 8;
      else if(c == '9')
	s3 += 9;
    }
  
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++){
	shape1[i][j] = shapes[s1][i][j];
	shape2[i][j] = shapes[s2][i][j];
	shape3[i][j] = shapes[s3][i][j];
      }
    shape1_nb = s1;
    shape2_nb = s2;
    shape3_nb = s3;

    if(s1 == -1){
      nb_shape = 1;
      this->del_shape();
    }
    if(s2 == -1){
      nb_shape = 2;
      this->del_shape();
    }
    if(s3 == -1){
      nb_shape = 3;
      this->del_shape();
    }
    file.close();
  }
}
