#include <stdio.h>

struct AB1 {
// LSB
	int aa;
	int bb;
// MSB
};

typedef struct {
// LSB
	char aa;
	char bb;
// MSB
} AB2;

typedef struct _AB3 {
// LSB
	char aa;
	int bb;
// MSB
} AB3;

//struct __attribute__((packed)) AB4 {
#pragma pack(push, 1)
struct AB4 {
// LSB
	char aa;
	int bb;
// MSB
};
#pragma pack(pop)

int main(int argc, char* argv[])
{
	long long int *p64 = NULL;
	struct AB1	ab1;
	AB2	ab2;
	AB3	ab3;
	struct AB4	ab4;

	printf("sizeof(struct AB1) = %lld\n", sizeof(struct AB1));
	printf("sizeof(struct AB2) = %lld\n", sizeof(AB2));
	printf("sizeof(struct AB3) = %lld\n", sizeof(struct _AB3));
	printf("sizeof(struct AB4) = %lld\n", sizeof(ab4));

	ab1.aa = 5;
	ab1.bb = 0x01020304;

	ab2.aa = 2;
	ab2.bb = 1;

	ab3.aa = 5;
	ab3.bb = 0x01020304;

	ab4.aa = 5;
	ab4.bb = 0x01020304;

	printf("ab1.aa = %Xh, ab1.bb = %Xh\n", ab1.aa, ab1.bb);
	printf("ab2.aa = %Xh, ab2.bb = %Xh\n", ab2.aa, ab2.bb);
	printf("ab3.aa = %Xh, ab3.bb = %Xh\n", ab3.aa, ab3.bb);
	printf("ab4.aa = %Xh, ab4.bb = %Xh\n", ab4.aa, ab4.bb);

	p64 = (long long int *)&ab1;
	printf("*p64(ab1) = %llXh\n", *p64);

	p64 = (long long int*) & ab2;
	printf("*p64(ab2) = %llXh\n", *p64);

	p64 = (long long int*) & ab3;
	printf("*p64(ab3) = %llXh\n", *p64);

	p64 = (long long int*) & ab4;
	printf("*p64(ab4) = %llXh\n", *p64);


	return 1;
}

