#pragma once
#include "config.h"
#include "ChessPoint.h"
#include "NOGO.h"
namespace NOGO {
	//NOGO_Rules
	////////////////////
	//包含对棋子的各种定义的判定 以及 落子是否符合规则 的判断
	class Rules {
	public:
		//获取棋子整个棋盘状态下的气
		static int get_qi(const ChessPoint& point);

		//获取棋子整个棋盘状态下的眼
		static int get_eye(const Color color );

		//判断该位置落子是否符合规则
		//if is kill myself or otherself return true 
		static bool is_kill(const ChessPoint& point);


	private:
		
	};//NOGO_Rules
}//namespace NOGO

