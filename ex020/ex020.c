#include <stdio.h>
#include <math.h>
#include <float.h>

void test1()
{
	float f = 0.1f;
	float sum = 0.0f;

	for (int i = 0; i < 10; i++) {
		sum += f;
	}

	printf("sum = %f\n", sum);
}

void test2()
{
	double d = 0.1;
	double sum = 0.0;

	for (int i = 0; i < 10; i++) {
		sum += d;
	}

	printf("sum = %lf\n", sum);
}

void test3()
{
	int i;
	float f1, f2;
	
	for (f1 = 1.0f, i = 0; i < 24; i++, f1 *= 2.0) {
		f2 = 1.0f / f1;

		printf("1 / %f = %13.10f\n", f1, f2);

	}
}

void main()
{
	test1();

	test2();

	test3();
}