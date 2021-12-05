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

		//if is kill myself or otherself return true 
		static bool is_kill(const ChessPoint& point);
		

		//eye
		
		//获取棋子整个棋盘状态下的眼
		static int get_eye(const Color color);

		//判断该棋子是否是自己的虎口 
		//@return 返回能够创建眼的个数
		static int is_jaws(const ChessPoint& point);

		//判断该棋子能否破掉对方的眼
		static bool is_Broken_eyes(const ChessPoint& point);
		

		//eligible
		
		//返回当前情况 下一个颜色的 所有可落子点
		static std::vector<ChessPoint&> eligible(const Color color);

		//返回是否是公共的可落子点
		static bool is_all_eligible(const ChessPoint& point);

		//返回当前情况 下一个颜色的 所有可落子点 中对手不可落子的点
		static std::vector<ChessPoint&> just_my_eligible(const Color color);


	private:
		//获取单个棋子的气
		static int get_this_qi(const ChessPoint& point);

		//if is kill myself return true 
		static bool is_kill_myself(const ChessPoint& point);

		//if is kill otherself return true 
		static bool is_kill_otherself(const ChessPoint& point);

		//判断单个棋子位置是否是棋子的眼
		static bool isEyes(ChessPoint point);


	};//NOGO_Rules
}//namespace NOGO

