#include <stdio.h>

#define var_concat(x, y)	x##y

#define to_str(s)	#s
#define to_str2(s1, s2)	to_str(s1##s2)

int main(int argc, char* argv[])
{
	int x = 1, y = 2, z = 3, xy = 5, yz = 10, xz = 15;

	printf("x = %d, y = %d, z = %d, xy = % d\n", x, y, z, xy);
	printf("x = %d, y = %d, z = %d, yz = % d\n", x, y, z, var_concat(y, z));
	printf("x = %d, y = %d, z = %d, " to_str2(x, z) " = %d\n", x, y, z, var_concat(x, z));

	return 1;
}