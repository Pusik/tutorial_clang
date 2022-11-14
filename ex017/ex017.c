#include <stdio.h>
#include <string.h>

struct Data {
	union {
		int	b32;

		struct {
			char	c1;
			char	c2;
			short	s1;
		};
	};
};


void main(void)
{
	int a;
	struct Data b;

	b.c1 = 'a';
	b.c2 = 'b';
	b.s1 = 256;
	
	printf("sizeof(int) = %lld, sizeof(struct Data) = %lld\n", sizeof(int), sizeof(struct Data));

#if 0
	memcpy(&a, &b, sizeof(struct Data));
#else
	a = *(int*) & b;
#endif
	printf("a = %08X\n", a);

}
