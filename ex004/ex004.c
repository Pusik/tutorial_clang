#include <stdio.h>

// Standard Predefined Macros

int main(int argc, char* argv[])
{
    int length = 245;

    fprintf(stdout, "Standard predefined macros: "
        "Arg: %d, "
        "File: %s, line %d\n",
        length, __FILE__, __LINE__);

    printf("Date: %s, Time; %s\n", __DATE__, __TIME__);
    
	return 1;
}