// 1. #pragma once --> Result
// 2. #pragma once --> Result
// 3. Remove '#pragma once' --> Error
// 4. #pragma once --> #ifndef 

#include <stdio.h>
#include "ex001_1.h"
#include "ex001_2.h"

int main(int argc, char* argv[])
{
	printf("A = %d\n", A);
}
