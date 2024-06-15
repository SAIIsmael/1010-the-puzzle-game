#ifndef __PIECE_H
#define __PIECE_H
#include <iostream>
#include "window.h"

class Piece {


private:
	int Pi[5][5];
	Color c;


public:
	//constructeur
	Piece();
	Piece(Color);

	//accesseur
	Color getColor() const;
	void setColor(Color);




	void setPiece(int);

};
#endif
