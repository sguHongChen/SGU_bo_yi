#include "Rules.h"

#include "NOGO.h"


namespace NOGO {
	static bool is_read[NoGo_Board_size][NoGo_Board_size];

	//初始化is_read
	static void clear_is_read() {
		for (size_t i = 0; i < NoGo_Board_size; i++) {
			for (size_t j = 0; j < NoGo_Board_size; j++) {
				is_read[i][j] = 0;
			}
		}
	}

	//获取棋子整个棋盘状态下的气
	int Rules::get_this_qi(const ChessPoint& point) {
		int sum = 0;
	    const char x = point.get_x();
		const char y = point.get_y();
		const Color color = point.get_color();
		if (is_read[x][y]) {
			return 0;
		}else{
			is_read[x][y] = 1;
		}
		
		//under
		if (x + 1 < NoGo_Board_size ){
			//if under don't have chess 
			if ((ChessBoard[x + 1][y] == no_chess)) {
				if (!is_read[x + 1][y]) {
					is_read[x + 1][y] = 1;
					sum++; 
				}
			}else if ((ChessBoard[x + 1][y] == color)) { //if under chess  do same as this chess
				const ChessPoint next_point(x+1, y ,color);
				sum += get_this_qi(next_point );
			}
		}
		
		// up 
		if (x - 1 > -1 ) {
			//if up don't have chess 
			if ((ChessBoard[x - 1][y] == no_chess)) {
				if (!is_read[x - 1][y]) {
					is_read[x - 1][y] = 1;
					sum++;
				}
			}
			else if ((ChessBoard[x - 1][y] == color)) { //if up chess  do same as this chess
				const ChessPoint next_point(x - 1, y ,color);
				sum += get_this_qi(next_point);
			}
		}
		
		//right
		if (y + 1 < NoGo_Board_size) {
			//if under don't have chess 
			if ((ChessBoard[x][y + 1] == no_chess)) {
				if (!is_read[x][y + 1]) {
					is_read[x][y + 1] = 1;
					sum++;
				}
			}
			else if ((ChessBoard[x][y+1] == color)) { //if under chess  do same as this chess
				const ChessPoint next_point( x , y + 1 ,color);
				sum += get_this_qi(next_point);
			}
		}
		
		if (y - 1 > -1 ) {
			//if under don't have chess 
			if ((ChessBoard[x][y - 1] == no_chess)) {
				if (!is_read[x][y - 1]) {
					is_read[x][y - 1] = 1;
					sum++;
				}
			}
			else if ((ChessBoard[x][y - 1] == color)) { //if under chess  do same as this chess
				const ChessPoint next_point(x, y - 1 , color);
				sum += get_this_qi(next_point);
			}
		}

		return sum;
	}

	//对外使用
	int Rules::get_qi(const ChessPoint& point) {
		clear_is_read();
		return Rules::get_this_qi(point);
	}

	//if is kill myself return true 
	bool Rules::is_kill_myself(const ChessPoint& point) {
		ChessBoard[point.get_x()][point.get_y()] = point.get_color();
		
		//如果棋子有气
		if (Rules::get_qi(point)) {
			ChessBoard[point.get_x()][point.get_y()] = no_chess;
			return false;
		}

		ChessBoard[point.get_x()][point.get_y()] = no_chess;
		return true;

	}

	//if is kill otherself return true 
	bool Rules::is_kill_otherself(const ChessPoint& point) {
		bool is_kill = 0;
		const char x = point.get_x();
		const char y = point.get_y();
		//模拟落子
		ChessBoard[x][y] = point.get_color();
		//获取对手棋子颜色
		const Color mate = - point.get_color();
		
		//under
		if (x + 1 < NoGo_Board_size &&
			(ChessBoard[x + 1][y] == mate)) {
			//if under chess is otherchess
			const ChessPoint mate_point(x + 1, y, mate);
			//如果造成对手棋子无气则返回
			if (!Rules::get_qi(mate_point)) {
				ChessBoard[x][y] = no_chess;
				return true;
			}
		}

		// up 
		if (x - 1 > -1 &&
			(ChessBoard[x - 1][y] == mate)) {
			//if up chess is otherchess
			const ChessPoint mate_point(x - 1, y, mate);
			//如果造成对手棋子无气则返回
			if (!Rules::get_qi(mate_point)) {
				ChessBoard[x][y] = no_chess;
				return true;
			}
		}

		//right
		if (y + 1 < NoGo_Board_size &&
			(ChessBoard[x][y + 1] == mate)) {
			//if right chess is otherchess
			const ChessPoint mate_point(x , y + 1, mate);
			//如果造成对手棋子无气则返回
			if (!Rules::get_qi(mate_point)) {
				ChessBoard[x][y] = no_chess;
				return true;
			}
		}

		if (y - 1 > -1 && (ChessBoard[x][y - 1] == mate)) {
			//if up chess is otherchess
			const ChessPoint mate_point(x, y - 1, mate);
			//如果造成对手棋子无气则返回
			if (!Rules::get_qi(mate_point)) {
				ChessBoard[x][y] = no_chess;
				return true;
			}
		}

		ChessBoard[x][y] = no_chess;
		return false;
	}

	//判断该位置落子是否符合规则
	//if is kill myself or otherself return true 
	bool Rules::is_kill(const ChessPoint& point) {
		return is_kill_myself(point) || is_kill_otherself(point);
	}


	//判断单个棋子位置是否是棋子的眼
	bool Rules::isEyes(ChessPoint point) {

		const char x = point.get_x();
		const char y = point.get_y();
		const Color color = point.get_color();

		// 如果上下左右有一个不是已方的棋子，则返回false
		if (x - 1 > -1 && ChessBoard[x - 1][y] != color) {
			return false;
		}
		if (x + 1 < NoGo_Board_size && ChessBoard[x + 1][y] != color) {
			return false;
		}
		if (y - 1 > -1 && ChessBoard[x][y - 1] != color) {
			return false;
		}
		if (y + 1 < NoGo_Board_size && ChessBoard[x][y + 1] != color) {
			return false;
		}
		
		// 如果在这个坐标下一子，判断是否是自杀
		if (is_kill_myself(point)) {
			clear_is_read();
			return false;
		}
		return true;
	}

	//根据棋手棋子颜色返回该棋手的眼的个数
	int Rules::get_eye(const Color color) {
		int eyes = 0;
		for (int i = 0; i < NoGo_Board_size; i++) {
			for (int j = 0; j < NoGo_Board_size; j++) {
				//只判断没有落子的位置
				if (ChessBoard[i][j] != no_chess) continue;
				ChessPoint eye_point(i, j, color);
				if (isEyes(eye_point)) {
					eyes++;
				}
			}
		}
		return  eyes;
	}

	//返回当前情况下一个颜色所有可以获得的所有落子点
	std::vector<ChessPoint&> Rules::eligible(const Color color) {
		//TODO  这个内存大小是可以改的更小的   可以加一点动态规划
		std::vector<ChessPoint&> ret(81);
		for (int i = 0; i < NoGo_Board_size; i++) {
			for (int j = 0; j < NoGo_Board_size; j++) {
				//只判断没有落子的位置
				if (ChessBoard[i][j] != no_chess) continue;
				ChessPoint eligible_point(i, j, color);

				//除去不符合规则的棋子
				if (is_kill(eligible_point)) continue;

				ret.push_back(eligible_point);
			}
		}
		return ret;
	}

	//返回是否是公共的可落子点
	bool Rules::is_all_eligible(const ChessPoint& point) {
		return !is_kill(point) ||
			!is_kill(ChessPoint(point.get_x(), point.get_y(), -point.get_color()));
	}

	//返回当前情况 下一个颜色的 所有可落子点 中对手不可落子的点
	std::vector<ChessPoint&> Rules::just_my_eligible(const Color color) {
		//TODO  这个内存大小是可以改的更小的   可以加一点动态规划
		std::vector<ChessPoint&> ret(81);

		for (int i = 0; i < NoGo_Board_size; i++) {
			for (int j = 0; j < NoGo_Board_size; j++) {
				//只判断没有落子的位置
				if (ChessBoard[i][j] != no_chess) continue;
				ChessPoint eligible_my_point(i, j, color);
				ChessPoint eligible_other_point(i, j, -color);
				//出去自己不能下的棋子
				if (is_kill(eligible_my_point)) continue;
				//保留对方不能下的棋子
				if (is_kill(eligible_other_point)) {
					ret.push_back(eligible_my_point);
				}
			}
		}


		return ret;
	}


	//判断该棋子是否是自己的虎口 
	//@return 返回能够创建眼的个数
	int Rules::is_jaws(const ChessPoint& point) {
		int jaws = 0;

		const char x = point.get_x();
		const char y = point.get_y();
		const Color color = point.get_color();
		
		if (ChessBoard[x][y] == no_chess) {
			jaws = get_eye(color);
			ChessBoard[x][y] == color;
			jaws = get_eye(color) - jaws;
			ChessBoard[x][y] == color;
		}

		return jaws;
	}

	//判断该棋子能否破掉对方的眼
	bool Rules::is_Broken_eyes(const ChessPoint& point) {
		return is_jaws(ChessPoint(point.get_x(), point.get_y(), -point.get_color()));
	}

}//namespace NOGO