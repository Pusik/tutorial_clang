#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("L: %d, This file is '%s'\n", __LINE__, __FILE__);

	printf("Function name: %s\n", __FUNCTION__);

	printf("Date: %s, Time: %s\n", __DATE__, __TIME__);
	

	return 1;
}
