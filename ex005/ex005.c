#include <stdio.h>

// Conditionals

#define KOREAN
void print_name(void)
{
#ifdef KOREAN
	printf("이름: 박부식\n");
#else
	printf("Name: Pusik Park\n");
#endif
}


#define	MONTH	12
#if (MONTH < 3) || (11 < MONTH)
char season[] = "Winter";
#elif MONTH > 9
char season[] = "Autumn";
#elif MONTH > 6
char season[] = "SUmmer";
#else
char season[] = "Spring";
#endif

int main(int argc, char* argv[])
{
	print_name();

	printf("It is %s\n", season);

#if 0
	printf("This is not used any more.\n");
#endif

	return 1;
}