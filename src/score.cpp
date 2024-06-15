#include "score.h"

Score::Score(int h, int w, int x, int y, char c): Window(h, w, x, y, c){
  score = 0;
  score_str = "Score : 0";
}


void Score::print_score(){
  this->Score::score_to_str();
  this->Window::print(5, 1, score_str);
}


void Score::score_to_str(){

  int score_temp = score;
  score_str = "";
  if (score == 0)
    score_str = "0";
  while(score_temp > 0){ 
    if (score_temp % 10 == 0)
      score_str = "0" + score_str;
    else if (score_temp % 10 == 1)
      score_str = "1" + score_str;
    else if (score_temp % 10 == 2)
      score_str = "2" + score_str;
    else if (score_temp % 10 == 3)
      score_str = "3" + score_str;
    else if (score_temp % 10 == 4)
      score_str = "4" + score_str;
    else if (score_temp % 10 == 5)
      score_str = "5" + score_str;
    else if (score_temp % 10 == 6)
      score_str = "6" + score_str;
    else if (score_temp % 10 == 7)
      score_str = "7" + score_str;
    else if (score_temp % 10 == 8)
      score_str = "8" + score_str;
    else if (score_temp % 10 == 9)
      score_str = "9" + score_str;

    score_temp /= 10;
  }
  score_str = "Score : " + score_str;
}

void Score::add_score(int x){
  if(x == 1)
    score += 10;
  else if (x == 2)
    score += 25;
  else if (x == 3)
    score += 45;
  else if (x == 4)
    score += 60;
  else if (x == 5)
    score += 75;
  else if (x == 6)
    score += 90;
}

void Score::score_save(){
  std::string name = "save";
  std::ofstream file(name.c_str(), std::ios::app);
  if(file){
    file << score;
    file.close();
  }
}


void Score::score_load(){
  char c;
  int score_temp = 0;
  std::string name = "save";
  std::ifstream file(name.c_str(), std::ios::in);

  if(file){
    score = 0;
    for(int i = 0; i < 106; i++)
      file.get(c);

    while(!file.eof()){
      if(c == '1')
	score_temp += 1;
      else if(c == '2')
	score_temp += 2;
      else  if(c == '3')
	score_temp += 3;
      else if(c == '4')
	score_temp += 4;
      else if(c == '5')
	score_temp += 5;
      else if(c == '6')
	score_temp += 6;
      else if(c == '7')
	score_temp += 7;
      else if(c == '8')
	score_temp += 8;
      else if(c == '9')
	score_temp += 9;

      file.get(c);
      
      if(!file.eof())
	score_temp *= 10;
    }
    file.close();
    score = score_temp;
  }
}


void Score::best_score(std::string pseudo){
  int top5[5];
  std::string pseudos[5];

  int score_temp = 0;
  char c;
  std::string name = "best_score";
  std::ifstream file(name.c_str(), std::ios::in);
  if(file){
    for(int i = 0; i < 5; i++){
      file.get(c);
      while(c != ':' &&  !file.eof()){
  
  if(c == '1')
    score_temp += 1;
  else if(c == '2')
    score_temp += 2;
  else  if(c == '3')
    score_temp += 3;
  else if(c == '4')
    score_temp += 4;
  else if(c == '5')
    score_temp += 5;
  else if(c == '6')
    score_temp += 6;
  else if(c == '7')
    score_temp += 7;
  else if(c == '8')
    score_temp += 8;
  else if(c == '9')
    score_temp += 9;
  
  file.get(c);
      
  if(c != ':')
    score_temp *= 10;
      }//fin du while
      top5[i] = score_temp;
      score_temp = 0;
    }//fin du for




///////////


for(int i = 0; i < 5; i++){
  file.get(c);
  pseudos[i] = "";

  while(c != ':' &&  !file.eof()){

    pseudos[i].push_back(c);
  
  file.get(c);
  }//fin du while
}//fin du for


///////////////


    file.close();
  }//fin du if


  if(score > top5[0]){
    top5[4] = top5[3];
    top5[3] = top5[2];
    top5[2] = top5[1];
    top5[1] = top5[0];
    top5[0] = score;
    pseudos[4] = pseudos[3];
    pseudos[3] = pseudos[2];
    pseudos[2] = pseudos[1];
    pseudos[1] = pseudos[0];
    pseudos[0] = pseudo;
  }
  else if(score > top5[1]){
    top5[4] = top5[3];
    top5[3] = top5[2];
    top5[2] = top5[1];
    top5[1] = score;
    pseudos[4] = pseudos[3];
    pseudos[3] = pseudos[2];
    pseudos[2] = pseudos[1];
    pseudos[1] = pseudo;
  }
  else if(score > top5[2]){
    top5[4] = top5[3];
    top5[3] = top5[2];
    top5[2] = score;
    pseudos[4] = pseudos[3];
    pseudos[3] = pseudos[2];
    pseudos[2] = pseudo;
  }
  else if(score > top5[3]){
    top5[4] = top5[3];
    top5[3] = score;
    pseudos[4] = pseudos[3];
    pseudos[3] = pseudo;
  }
  else if(score > top5[4]){
    top5[4] = score;
    pseudos[4] = pseudo;
  }

  std::ofstream file2(name.c_str(), std::ios::out);

  if(file2){
    for(int i = 0; i < 5; i++){
      file2 << top5[i] << ":";
    }
    for(int i = 0; i < 5; i++){
      file2 << pseudos[i] << ":";
    }
    file2.close();
  }
}
