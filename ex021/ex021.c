#include <stdio.h>

// [C 언어] 포인터로 2차원 배열 다루기 (주소 접근 및 원소 값 접근)
// https://wonit.tistory.com/527

// https://stackoverflow.com/questions/1119134/how-do-malloc-and-free-work

void test1();

void main()
{
	test1();
}

void test1()
{
	int arr[3][5] = {
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14, 15}
	};

	int(* ptr1)[5]; // 행을 3로 하는 2차원 배열 포인터 하나 생성
	ptr1 = arr;

	printf("arr = %p\n", arr);
	printf("arr[0] = %p\n", arr[0]);
	printf("arr[1] = %p, arr[1] - arr[0] = %llXh\n", arr[1], arr[1] - arr[0]);	// 포인터의 +/- 연산을 위해서는 포인터의 데이터 타입을 알아야 한다.
	printf("arr[2] = %p, arr[2] - arr[0] = %llXh\n", arr[2], arr[2] - arr[0]);
	printf("&arr[0][0] = %p\n", &arr[0][0]);
	printf("&arr[1][0] = %p, &arr[1][0] - &arr[0][0] = %llXh\n", &arr[1][0], &arr[1][0] - &arr[0][0]);
	printf("&arr[2][0] = %p, &arr[2][0] - &arr[0][0] = %llXh\n", &arr[2][0], &arr[2][0] - &arr[0][0]);

	long long int addr2 = arr[2];
	long long int addr1 = arr[1];
	long long int addr0 = arr[0];

	printf("\naddr0 = %llXh\n", addr0);
	printf("addr1 = %llXh, addr1 - addr0 = %llXh\n", addr1, addr1 - addr0);
	printf("addr2 = %llXh, addr2 - addr0 = %llXh\n", addr2, addr2 - addr0);


	ptr1 = arr;
	printf("\nptr1 = %p\n", ptr1);
	printf("*ptr1 + 1 = %p\n", *ptr1 + 1);
	printf("*ptr1 + 2 = %p\n", *ptr1 + 2);
	printf("*ptr1 + 3 = %p\n", *ptr1 + 3);
	printf("*ptr1 + 4 = %p\n", *ptr1 + 4);

	printf("*(ptr1 + 1) = %p\n", *(ptr1 + 1));
	printf("*(ptr1 + 1) + 1 = %p\n", *(ptr1 + 1) + 1);
	printf("*(ptr1 + 1) + 2 = %p\n", *(ptr1 + 1) + 2);
	printf("*(ptr1 + 1) + 3 = %p\n", *(ptr1 + 1) + 3);
	printf("*(ptr1 + 1) + 4 = %p\n", *(ptr1 + 1) + 4);

	printf("*(ptr1 + 2) = %p\n", *(ptr1 + 2));
	printf("*(ptr1 + 2) + 1 = %p\n", *(ptr1 + 2) + 1);
	printf("*(ptr1 + 2) + 2 = %p\n", *(ptr1 + 2) + 2);
	printf("*(ptr1 + 2) + 3 = %p\n", *(ptr1 + 2) + 3);
	printf("*(ptr1 + 2) + 4 = %p\n", *(ptr1 + 2) + 4);
	
	ptr1 = arr;
	printf("\nptr1 = %p\n", ptr1);
	ptr1++;
	printf("ptr1++; ptr1 = %p\n", ptr1);
	ptr1++;
	printf("ptr1++; ptr1 = %p\n", ptr1);


	int** ptr2;
	ptr2 = arr;
	printf("\nptr2 = %p\n", ptr2);
	ptr2++;
	printf("ptr2++; ptr2 = %p\n", ptr2);
	ptr2++;
	printf("ptr2++; ptr2 = %p\n", ptr2);
	
	int** ptr3;
	ptr3 = arr;
	printf("\nptr3 = %p\n", ptr3);
	*ptr3++;
	printf("*ptr3++; ptr2 = %p\n", ptr3);
	*ptr3++;
	printf("*ptr3++; ptr2 = %p\n", ptr3);

}

/*
	Where Should Malloc be used?

	1. Dynamic Memory allocation
		Dynamic Memory Allocation helps us allocate a piece of memory as per the user¡¯s demand. It returns a pointer to the start of that memory, which could be treated similarly to an array.

	2. Heap memory
		malloc() allocates the memory location on the heap and returns a pointer on the stack pointing to the starting address of the array type memory being allocated whereas the static array size put a hard upper limit on how much data the program could process at any one time, without being recompiled.

	3. Better lifetime
		Variables or Arrays created using malloc exist for a lifetime until they are cleared. This is of great importance for various data structures such as linked lists, binary heap, etc.
*/
void test2()
{
	int *a[5];

	a[0] = (int *)malloc(16);
	if (a[0] == NULL) {
		printf("malloc(16) failed\n");
	}
	memset(a[0], 0, 16);
	a[1] = (int *)malloc(32);
	if (a[1] == NULL) {
		printf("malloc(32) failed\n");
	}
	memset(a[1], 0, 32);
	a[2] = (int *)malloc(64);
	if (a[2] == NULL) {
		printf("malloc(64) failed\n");
	}
	memset(a[2], 0, 64);
	a[3] = (int *)malloc(128);
	if (a[3] == NULL) {
		printf("malloc(128) failed\n");
	}
	memset(a[3], 0, 128);
	a[4] = (int *)malloc(256);
	if (a[4] == NULL) {
		printf("malloc(256) failed\n");
	}
	memset(a[4], 0, 256);

	printf("a[0] = %p\n", a[0]);
	printf("a[1] = %p, (a[0] - a[1] = %llXh)\n", a[1], a[0] - a[1]);
	printf("a[2] = %p, (a[1] - a[2] = %llXh)\n", a[2], a[1] - a[2]);
	printf("a[3] = %p, (a[2] - a[3] = %llXh)\n", a[3], a[2] - a[3]);
	printf("a[4] = %p, (a[3] - a[4] = %llXh)\n", a[4], a[3] - a[4]);

	free(a[4]);
	free(a[1]);
	free(a[0]);
	free(a[2]);
	free(a[3]);
}