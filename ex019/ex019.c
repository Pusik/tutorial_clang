#include <stdio.h>
#include <math.h>
#include <float.h>

void test0()
{
	int i1 = 1, i2 = 2, i3;
	
	i3 = i1 + i2;

	printf("%d + %d = %d\n", i1, i2, i3);
}

void test1()
{
	float f32 = 0.1f;
	double f64 = 0.1;

	if (f32 == 0.1)	printf("double data\n");
	else if (f32 == 0.1f)	printf("float data\n");

	if (f64 == 0.1)	printf("double data\n");
	else if (f64 == 0.1f)	printf("float data\n");


	printf("sizeof(f32) = %lld\n", sizeof(f32));
	printf("sizeof(f64) = %lld\n", sizeof(f64));


	long int* p32 = (long int*)&f32;
	long long int* p64 = (long long int*) & f64;

	printf("*p32 = %lXh, *p64 = %llXh\n", *p32, *p64);

	if (f32 == f64)	printf("f32 and f64 are same\n");
	else	printf("f32 and f64 are different\n");
}

void test2()
{
	long int* p32 = NULL;
	float f = 10.327;
	int i = 28;

	float sum = f + i;

	printf("Float data is %f\n", f);
	printf("Integer data is %d\n", i);
	printf("Sum data is %f\n", sum);
}

void test3()
{
	long long int* p64 = NULL;
	float f1 = 10.32;
	float f2 = 44.50;
	float sum = f1 + f2;

	printf("Float data is %f, %f\n", f1, f2);
	printf("Sum is %f\n", sum);
}

void test4()
{
	long long int* p64 = NULL;
	float f = 10.327;
	double d = 28.33, sum;
	
	sum = d + f;

	printf("Float data is %f\n", f);
	printf("Double data is %lf\n", d);
	printf("Sum is %lf\n", sum);
}

void test5()
{
	long long int* p64 = NULL;
	double d1 = 10.327;
	double d2 = 4244.546;
	double sum = d1 + d2;

	printf("Double data is %lf, %lf\n", d1, d2);
	printf("Sum is %lf\n", sum);
}

int main(int argc, char* argv[])
{
	test0();

	test1();

	test2();

	test3();

	test4();

	test5();

	return 1;
}
