#include "myprogram.h"
#include "shape.h"

//demande du pseudo

std::string pseudo = "Unknow";

void set_pseudo(){

	std::string pseudo_tmp;

	std::cout << "Veuillez saisir votre pseudo" << std::endl;
	std::cin >> pseudo_tmp;

	pseudo = pseudo_tmp;
}


// mise en place du score

std::string setup_score(int x){
  int tmp = x;
  std::string res = "";
  if(tmp == 0)
    res = "0";
  while(tmp > 0){
    if(tmp%10 == 0)
      res = "0" + res;
    else if(tmp%10 == 1)
      res = "1" + res;
    else if(tmp%10 == 2)
      res = "2" + res;
    else if(tmp%10 == 3)
      res = "3" + res;
    else if(tmp%10 == 4)
      res = "4" + res;
    else if(tmp%10 == 5)
      res = "5" + res;
    else if(tmp%10 == 6)
      res = "6" + res;
    else if(tmp%10 == 7)
      res = "7" + res;
    else if(tmp%10 == 8)
      res = "8" + res;
    else if(tmp%10 == 9)
      res = "9" + res;

    tmp /= 10;
  }
  res = "Score : " + res;
  return res;
}

// remplace les pieces par un fichier

void set_shapes(std::string name){
  char c;
  int car;

  std::ifstream file(name.c_str(), std::ios::in);
  if(file){
    for(int i = 0; i < 14; i++)
      for(int j = 0; j < 5; j ++)
	for(int k = 0; k < 5; k++){
	  file.get(c);
	  if(c == '0')
	    car = 0;
	  else if(c == '1')
	    car = 1;
	  else if(c == '2')
	    car = 2;
	  else if(c == '3')
	    car = 3;
	  else if(c == '4')
	    car = 4;
	  else if(c == '5')
	    car = 5;
	  else if(c == '6')
	    car = 6;
	  else if(c == '7')
	    car = 7;
	  else if(c == '8')
	    car = 8;
	  else if(c == '9')
	    car = 9;

	  shapes[i][j][k] = car;
	}
    file.close();
  }
}



// DEBUT DE MYPROGRAM


void myprogram(){
  srand(time(NULL));

  //set_shapes("set_1");

  int nb_s1, nb_s2, nb_s3;
  bool s1_placeable, s2_placeable, s3_placeable;
  
  int c;
  bool perdu = false;


  
  Window menu 		(31, 48,  1,  0);
  menu.setCouleurBordure(BBLUE);
  menu.print		(16,5,"Bienvenue " + pseudo,WRED);



  menu.print		(2,20,"Pour demarrer le jeu, appuyez sur la touche x",WBLUE);
  menu.print		(2,22,"Pour quitter le jeu, appuyez sur la touche q",WBLUE);

//////////////
  Score score2 (0,  0, 0,  3000);


  score2.best_score(pseudo);
  int score_tmp2 = 0;
  char c_best_score2;
  int best_score2[5];
  std::string name_best_score2 = "best_score";
  std::ifstream file_best_score2(name_best_score2.c_str(), std::ios::in);
  
  if(file_best_score2){
    for(int i = 0; i < 5; i++){
      file_best_score2.get(c_best_score2);
      while(c_best_score2 != ':' && !file_best_score2.eof()){
	
	if(c_best_score2 == '1')
	  score_tmp2 += 1;
	else if(c_best_score2 == '2')
	  score_tmp2 += 2;
	else if(c_best_score2 == '3')
	  score_tmp2 += 3;
	else if(c_best_score2 == '4')
	  score_tmp2 += 4;
	else if(c_best_score2 == '5')
	  score_tmp2 += 5;
	else if(c_best_score2 == '6')
	  score_tmp2 += 6;
	else if(c_best_score2 == '7')
	  score_tmp2 += 7;
	else if(c_best_score2 == '8')
	  score_tmp2 += 8;
	else if(c_best_score2 == '9')
	  score_tmp2 += 9;
	
	file_best_score2.get(c_best_score2);
	
	if(c_best_score2 != ':')
	  score_tmp2 *= 10;
      }//fin while
      best_score2[i] = score_tmp2;
      score_tmp2 = 0;
    }//fin for

    std::string pseudos[5];

  
  		for(int i = 0; i < 5; i++){
  			file_best_score2.get(c_best_score2);
  			pseudos[i] = "";

  			while(c_best_score2 != ':' &&  !file_best_score2.eof()){
    			pseudos[i].push_back(c_best_score2);
    			file_best_score2.get(c_best_score2);
    		}//fin du while
  		}//fin du for

    	file_best_score2.close();

    	menu.print (6,10,"N.1 " + pseudos[0] + " : " + setup_score(best_score2[0]),WBLUE);
  		menu.print (6,11,"N.2 " + pseudos[1] + " : " + setup_score(best_score2[1]),WBLUE);
  		menu.print (6,12,"N.3 " + pseudos[2] + " : " + setup_score(best_score2[2]),WBLUE);
  		menu.print (6,13,"N.4 " + pseudos[3] + " : " + setup_score(best_score2[3]),WBLUE);
  		menu.print (6,14,"N.5 " + pseudos[4] + " : " + setup_score(best_score2[4]),WBLUE);
  

  	}//fin if
  

  
  
  //////////////


  ///////////////////////////////////////////////////////

  c = getch();
  
  while(c !='x' && c != 'q'){
    c = getch();
  }

  
  Score score (3,  23, 12,  2);
  Board board (10, 10, 25, 9);
  Choice choice (19, 7, 12, 9, shapes, rand() % 14);
  Window bordure (31, 48,  1,  0);

  bordure.setCouleurBordure(BBLUE);
  score.setCouleurBordure(BRED);
  board.setCouleurBordure(BGREEN);
  choice.setCouleurBordure(BYELLOW);
  board.set_shape(choice.get_shape(1), shapes[choice.get_shape(1)]);

  
  
  while(c !='q' && !perdu){
    if(c == KEY_UP ||
       c == KEY_DOWN ||
       c == KEY_RIGHT ||
       c == KEY_LEFT ||
       c == 10 ||
       c == 'x' ||
       c == 's' ||
       c == 'l' ||
       c == '1' ||
       c == '2' ||
       c == '3' ||
       c == '4' ||
       c == '5' ||
       c == '6' ||
       c == '7' ||
       c == '8' ||
       c == '9' ||
       c == 'c')
      {
	if(c == KEY_UP)
	  board.up();
	if(c == KEY_DOWN)
	  board.down();
	if(c == KEY_RIGHT)
	  board.right();
	if(c == KEY_LEFT)
	  board.left();
	if(c == '1')	  
	  board.set_shape(choice.get_shape(1), shapes[choice.get_shape(1)]);
	if(c == '2')
	  board.set_shape(choice.get_shape(2), shapes[choice.get_shape(2)]);
	if(c == '3')
	  board.set_shape(choice.get_shape(3), shapes[choice.get_shape(3)]);
	if(c == '4')
	  choice.set_choice(rand(), rand(), rand());
	if(c == '5')
	  choice.set_choice(1, 2, 3);
	if(c == '9')
	  score.best_score(pseudo);
	if(c == 'c')
	  board.clear_lines();
	if(c == 's'){
	  board.board_save();
	  choice.choice_save();
	  score.score_save();
	}
	if(c == 'l'){
	  board.board_load();
	  choice.choice_load();
	  score.score_load();
	  board.set_shape(choice.get_shape(1), shapes[choice.get_shape(1)]);
	}

	if(c == 10){
	  if (board.add_piece(board.get_pos_x(), board.get_pos_y()))
	    if(choice.del_shape())
	      choice.set_choice(rand(), rand(), rand());
	  
	 
	  score.add_score(board.clear_lines());

	  board.set_shape(choice.get_shape(1), shapes[choice.get_shape(1)]);
	}
	

	board.clear();
	board.print_board();
	choice.clear();
	choice.print_choice();
	score.clear();
	score.print_score();
	
	// gestion de la defaite
	nb_s1 = choice.get_shape2(1);
	nb_s2 = choice.get_shape2(2);
	nb_s3 = choice.get_shape2(3);
	
	if(nb_s1 != -1)
	  s1_placeable = board.is_placeable(shapes[nb_s1]);
	else
	  s1_placeable = false;
	
	if(nb_s2 != -1)
	  s2_placeable = board.is_placeable(shapes[nb_s2]);
	else
	  s2_placeable = false;
	
	if(nb_s3 != -1)
	  s3_placeable = board.is_placeable(shapes[nb_s3]);
	else
	  s3_placeable = false;
	
	if ( ! (s1_placeable || s2_placeable || s3_placeable))
	  perdu = true;
	
    }
    c = getch();
  }
  


  score.best_score(pseudo);
  int score_tmp = 0;
  char c_best_score;
  int best_score[5];
  std::string name_best_score = "best_score";
  std::ifstream file_best_score(name_best_score.c_str(), std::ios::in);
  
  if(file_best_score){
    for(int i = 0; i < 5; i++){
      file_best_score.get(c_best_score);
      while(c_best_score != ':' && !file_best_score.eof()){
	
	if(c_best_score == '1')
	  score_tmp += 1;
	else if(c_best_score == '2')
	  score_tmp += 2;
	else if(c_best_score == '3')
	  score_tmp += 3;
	else if(c_best_score == '4')
	  score_tmp += 4;
	else if(c_best_score == '5')
	  score_tmp += 5;
	else if(c_best_score == '6')
	  score_tmp += 6;
	else if(c_best_score == '7')
	  score_tmp += 7;
	else if(c_best_score == '8')
	  score_tmp += 8;
	else if(c_best_score == '9')
	  score_tmp += 9;
	
	file_best_score.get(c_best_score);
	
	if(c_best_score != ':')
	  score_tmp *= 10;
      }//fin while
      best_score[i] = score_tmp;
      score_tmp = 0;
    }//fin for

std::string pseudos2[5];
  	for(int i = 0; i < 5; i++){
  		file_best_score.get(c_best_score2);
  		pseudos2[i] = "";

  		while(c_best_score2 != ':' &&  !file_best_score.eof()){
    		pseudos2[i].push_back(c_best_score2);
    		file_best_score.get(c_best_score2);
    	}//fin du while
  	}//fin du for

 	menu.clear();
    menu.print (6,10,"N.1 " + pseudos2[0] + " : " + setup_score(best_score[0]),WBLUE);
  	menu.print (6,11,"N.2 " + pseudos2[1] + " : " + setup_score(best_score[1]),WBLUE);
  	menu.print (6,12,"N.3 " + pseudos2[2] + " : " + setup_score(best_score[2]),WBLUE);
  	menu.print (6,13,"N.4 " + pseudos2[3] + " : " + setup_score(best_score[3]),WBLUE);
  	menu.print (6,14,"N.5 " + pseudos2[4] + " : " + setup_score(best_score[4]),WBLUE);
  
    file_best_score.close();
  }//fin if
  
  

  
  menu.print (16,5,"Vous avez perdu",WRED);
  menu.print (2,22,"Pour fermer, appuyez sur la touche q",WBLUE);
 
  while(c !='q'){
    c = getch();
  }
}