#include <stdio.h>

#define my_printf(...)	printf("Pusik: " __VA_ARGS__)

int is_larger(int base, int x1, int x2, int x3) {
	if (x1 > base && x2 > base && x3 > base) return 1;
	else if(x1 < base && x2 < base && x3 < base)	return -1;
	return 0;
}

//define IS_LARGER_180cm(format, ...)	is_larger(180, format, __VA_ARGS__)

#define IS_LARGER_180cm(...)	is_larger(180, __VA_ARGS__)


int main(int argc, char* argv[])
{
	my_printf("Hello, World!\n");

	my_printf("My age is %d\n", 46);

	printf("%d\n", IS_LARGER_180cm(190, 195, 200));

	return 1;
}

