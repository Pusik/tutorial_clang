#include <stdio.h>

void main(void)
{
	long long int data = 0x1020304050607;//0x0001020304050607;
	char *p8 = (char *)&data;

	printf("data = %llXh\n", data);
	
#if 0
	for (; *p8 != NULL; p8++) {
		*p8 += 'A';
	}
#else 
	while (*p8 != NULL) {
		*p8++ += 'A';
	}
#endif

	printf("data = %llXh\n", data);
	printf("data = '%s'\n", (char *)&data);

	printf("%c = %d(%Xh)\n", 'A', 'A', 'A');
	printf("%c = %d(%Xh)\n", 65+1, 65+1, 65+1);
	printf("%c = %d(%Xh)\n", 0x41+2, 0x41+2, 0x41+2);
}