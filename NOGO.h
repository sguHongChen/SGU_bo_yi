#include <vector>
#include "config.h"
//NOGO ��Χ��
namespace NOGO {
	//����
	extern std::vector<std::vector<Color>> ChessBoard;
	
	//��ʼ������
	void clear();
	
	//custom  assert
	void do_assert(const bool condition, const char* fmt, ...);
}//NOGO