#include <stdio.h>



void print_morning(void)
{
	printf("Good Morning.\n");
}

void print_night(void)
{
	printf("Good Night.\n");
}

void test1()
{
	int is_night;
	void (*print_func)(void);
	
	is_night = 0;

	if (is_night)
		print_func = print_night;
	else
		print_func = print_morning;

	print_func();

	void (*print_func2)(int);
	print_func2 = print_night;

	//print_func2();
}

void print_increment(int a)
{
	printf("%d\n", a + 1);
}

void test2()
{
	void (*print_func)(void);

	print_func = print_increment;

	print_func();
}

void print_add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

void test3()
{
	int (*op_func)(int a, int b);

	op_func = print_add;

	int sum = op_func(1, 2);

	printf("sum = %d\n", sum);
}

#if 1
int func_add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);

	return a + b;
}

void test4()
{
	int sum;
	void (*op_func)(int a, int b);

	op_func = func_add;

	sum = op_func(1, 2);

	printf("sum = %d\n", sum);
}
#endif

void main()
{
	test1();

	test2();

	test3();

#if 1
	test4();
#endif
}