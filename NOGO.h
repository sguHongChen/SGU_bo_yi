#include <vector>
#include "config.h"
//NOGO ≤ªŒß∆Â
namespace NOGO {
	//∆Â≈Ã
	extern std::vector<std::vector<Color>> ChessBoard;
	
	//≥ı ºªØ∆Â≈Ã
	void clear();
	
	//custom  assert
	void do_assert(const bool condition, const char* fmt, ...);
}//NOGO