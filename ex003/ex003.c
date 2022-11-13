#include <stdio.h>
#include <time.h>

// Variadic Macros

#define k_printf(...)	printf("KETI: " __VA_ARGS__)

int main(int argc, char* argv[])
{
	printf("Hello world (T: %lld)\n", time(NULL));

	k_printf("Hello world (T: %lld)\n", time(NULL));

	return 1;
}