#include <stdio.h>

void func_a()
{
	printf("This is a function\n");
}

#define func_b	func_a
#define func_c()	func_a()
//#define func_d ()	func_a()

#if 0
#define func_var(x)	x, "x"
#endif

#define init_var(x) x, x = 0

int main(int argc, char* argv[])
{
	func_a();

	func_b();

	func_c();

	//func_d();
#if 0
	int a = func_var(5);

	printf("%d\n", func_var(5));
#endif
	
	int x = 5;
	for (int i = init_var(x); i < 10; i++, x++) {
		printf("i = %d, x = %d\n", i, x);
	}

	return 1;
}

