#include <stdio.h>

struct BF1 {
	// LSB
	int i0;
	int i1;
	// MSB
};

struct BF2 {
	// LSB
	short s0;
	short s1;
	short s2;
	short s3;
	// MSB
};

struct BF3 {
	// LSB
	char c0;
	char c1;
	char c2;
	char c3;
	char c4;
	char c5;
	char c6;
	char c7;
	// MSB
};

struct BF4 {
	// LSB
	char c0;
	char c1;
	short s0;
	int i0;
	// MSB
};

struct BF5 {
	// LSB
	int i0;
	short s0;
	char c0;
	char c1;
	// MSB
};



int main(int argc, char* argv[])
{
	long long int data = 0x0102030405060708;

	struct BF1 *p1 = (struct BF1 *)&data;
	struct BF2 *p2 = (struct BF2 *)&data;
	struct BF3 *p3 = (struct BF3 *)&data;
	struct BF4 *p4 = (struct BF4 *)&data;
	struct BF5 *p5 = (struct BF5 *)&data;

	printf("BF1.i1 = %Xh, BF1.i0 = %Xh\n", p1->i1, p1->i0);
	printf("BF2.s3 = %Xh, BF2.s2 = %Xh, BF2.s1 = %Xh, BF2.s0 = %Xh\n", 
		p2->s3, p2->s2, p2->s1, p2->s0);
	printf("BF3.c7 = %Xh, BF3.c6 = %Xh, BF3.c5 = %Xh, BF3.c4 = %Xh, "
			"BF3.c3 = %Xh, BF3.c2 = %Xh, BF3.c1 = %Xh, BF3.c0 = %Xh\n", 
		p3->c7, p3->c6, p3->c5, p3->c4, p3->c3, p3->c2, p3->c1, p3->c0);
	printf("BF4.c0 = %Xh, BF4.c1 = %Xh, BF4.s0 = %Xh, BF4.i0 = %Xh\n", p4->c0, p4->c1, p4->s0, p4->i0);
	printf("BF5.c0 = %Xh, BF5.c1 = %Xh, BF5.s0 = %Xh, BF5.i0 = %Xh\n", p5->c0, p5->c1, p5->s0, p5->i0);

	return 1;
}

