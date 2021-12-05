#include "config.h"

//∆Â≈Ã÷–µƒŒª÷√
class ChessPoint{
public :
	ChessPoint();
	ChessPoint(const char x , const char y  ,  const Color color );
	const char get_x() const ;
	const char get_y() const ;
	const Color get_color() const;

private:
	Color color = no_chess;
	char x = 0;
	char y = 0;
};

