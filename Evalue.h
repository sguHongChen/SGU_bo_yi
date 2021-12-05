#pragma once
#include "NOGO.h"
#include "ChessPoint.h"
namespace NOGO {
	class Evalue
	{
	public:
		//静态评估函数
		static int evalue(const ChessPoint& point);
	private:
		//返回己方可落子的个数减去对方可落子的个数
		int more_eligible(const Color color);

		//返回对方不可落子的个数
		int more_eligible(const Color color);

		//返回己方活眼数减对方活眼数
		int more_eligible(const Color color);

		//TODO  在自己可以落子对方不能落子的位置集合里，
		//优先下对方落子后这个位置有可能变成对方不能下自己也不能下的位置


	};
}
