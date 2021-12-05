#include "NOGO.h"
namespace NOGO {
	std::vector<std::vector<Color>> ChessBoard(NoGo_Board_size, std::vector<Color>(NoGo_Board_size));

	void clear(){
		for (size_t i = 0; i < NoGo_Board_size; i++) {
			for (size_t j = 0; j < NoGo_Board_size; j++) {
				ChessBoard[i][j] = no_chess;
			}
		}
	}

	//custom  assert
	void do_assert(const bool condition, const char* fmt, ...) {
		if (!condition) {
			//log to console
			va_list ap;
			va_start(ap, fmt);
			vfprintf(stderr, fmt, ap);
			va_end(ap);
		}
	}

}//namespace NOGO