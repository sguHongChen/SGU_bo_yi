#include<iostream>
#include "test.h"
#include "NOGO.h"
#include "Rules.h"

namespace NOGO {
	test::test() {
	}

	//qi_test
	void qi_test() {
		NOGO::clear();
		ChessBoard[0][2] = white_chess;
		ChessBoard[1][1] = white_chess;
		ChessBoard[1][2] = black_chess;
		ChessBoard[1][3] = white_chess;
		ChessBoard[2][2] = white_chess;
		const ChessPoint k_point(1 , 2, black_chess);
		const ChessPoint l_point(5 , 5, black_chess);
		std::cout << Rules::get_qi(k_point);
		bool k = Rules::is_killer(k_point);
		bool l = Rules::is_killer(l_point);
		std::cout <<"k=" << k << "l=" << l;
	}


	void test_color() {
		std::cout << -black_chess<<std::endl;
		std::cout << -white_chess;
	}

	void test::NOGO_main() {
		qi_test();   
		//test_color();  1  -1
	}
}//NOGO

