#include <stdio.h>



void op_increment1(int a)
{
	printf("Address of 'a'(op_increment1) = %p\n", &a);

	a++;
}

void test1()
{
	int a = 10;
	
	printf("Address of 'a'(test1) = %p\n", &a);

	op_increment1(a);

	printf("Address of 'a'(test1) = %p\n", &a);

	printf("a = %d\n", a);
}

void op_increment2(int* a) {
	printf("Address of 'a'(op_increment2) = %p\n", a);

	*a++;
}

void test2() {
	int a = 10;

	printf("Address of 'a'(test2) = %p\n", &a);

	op_increment2(&a);

	printf("Address of 'a'(test2) = %p\n", &a);

	printf("a = %d\n", a);
}

void op_increment3(int& a) {
	printf("Address of 'a'(op_increment2) = %p\n", &a);

	a++;
}

void test3() {
	int a = 10;

	printf("Address of 'a'(test2) = %p\n", &a);

	op_increment3(a);

	printf("Address of 'a'(test2) = %p\n", &a);

	printf("a = %d\n", a);
}

void main()
{
	test1();

	test2();

	test3();
}