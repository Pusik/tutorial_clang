#include <stdio.h>

#define MOTHER
#define FATHER

#if !defined(MOTHER) || !defined(FATHER)
#error "A baby can't be borned.'"
#endif


int main(int argc, char* argv[])
{


	return 1;
}

