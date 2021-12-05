#include <iostream>
#include "test.h"
static void test1() {
	std::cout << (black_chess == white_chess) << std::endl;
	std::cout << (black_chess == no_chess) << std::endl;
	std::cout << (black_chess == black_chess) << std::endl;
}
int main() {
	NOGO::test t;
	t.NOGO_main();
}//main