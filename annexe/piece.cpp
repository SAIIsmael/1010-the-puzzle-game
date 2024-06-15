#include "../headers/piece.h"
#include "../headers/shape.h"

Piece::Piece(){c=WBLACK;}
Piece::Piece(Color col){c=col;}

Color Piece::getColor() const{return c;}
void  Piece::setColor(Color col){c=col;}


void Piece::setPiece(int id){

for (int i = 0; i < 5; ++i)
{
	for (int j = 0; j < 5; ++j)
	{
		Pi[i][j]=shapes[id][i][j];
	}
}


}
