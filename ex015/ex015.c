#include <stdio.h>

union U1 {
	int a;
	int b;
	int c;
};

union U2 {
	struct {
		// LSB
		int a;
		// MSB
	};

	struct {
		// LSB
		int b;
		int c;
		// MSB
	};
};

union U1_1 {
	// LSB
	char a;
	short b;
	int c;
	// MSB
};

union U1_2 {
	char a;
	short b;
	short c;
};

union U1_3 {
	char a;
	char b;
	char c;
};

void main(void)
{
	printf("sizeof(union U1) = %lld\n", sizeof(union U1));
	printf("sizeof(union U2) = %lld\n", sizeof(union U2));

	printf("sizeof(union U1_1) = %lld\n", sizeof(union U1_1));
	printf("sizeof(union U1_2) = %lld\n", sizeof(union U1_2));
	printf("sizeof(union U1_3) = %lld\n", sizeof(union U1_3));

	union U1	d1;

	d1.a = 0x01020304;

	printf("U1.a = %Xh, U1.b = %Xh, U1.c = %Xh\n", d1.a, d1.b, d1.c);

	union U2	d2;

	d2.b = 0x01020304;
	d2.c = 0x05060708;

	printf("U2.a = %Xh, U2.b = %Xh, U2.c = %Xh\n", d2.a, d2.b, d2.c);

	union U1_1	d1_1;

	d1_1.c = 0x01020304;

	printf("U1_1.a = %Xh, U1_1.b = %Xh, U1_1.c = %Xh\n", d1_1.a, d1_1.b, d1_1.c);
}
