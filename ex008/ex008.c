#include <stdio.h>

void func_a()
{
	printf("This is a function\n");
}

#define func_b	func_a
#define func_c()	func_a()
#define func_d ()	func_a()

int main(int argc, char* argv[])
{
	func_a();

	func_b();

	func_c();

	func_d();

	return 1;
}

