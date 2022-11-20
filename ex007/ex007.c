#include <stdio.h>

void func_a()
{
	printf("This is a function\n");
}

#define func_b	func_a
#define func_c()	func_a()
//#define func_d ()	func_a()

#define plus_one(x)	x+1

int main(int argc, char* argv[])
{
	int a;

	func_a();

	func_b();

	func_c();

	//func_d();

	
	a = 5 * plus_one(3);

	printf("a = %d\n", a);

	return 1;
}

