#include <stdio.h>

void test1() 
{
	int var1 = 2;
	short var2[2] = {/*LSB*/2, 1/*MSB*/ };
	char var3[4] = {/*LSB*/4, 3, 2, 1/*MSB*/ };
	int* p32 = NULL;

	printf("Test 1 =============\n\n");

	printf("Address of var1 = %p\n", &var1);
	printf("Address of var2 = %p\n", var2);
	printf("Address of var3 = %p\n", var3);
	printf("p = %p\n", p32);

	p32 = &var1;	// store address of var1 in pointer variable

	printf("p32 (<= &var1) = %p\n", p32);

	p32 = (int*)var2;	// store address of var2 in pointer variable

	printf("p32 (<= var2) = %p\n", p32);

	p32 = (int*)var3;	// store address of var3 in pointer variable

	printf("p32 (<= var3) = %p\n", p32);


	p32 = (int*)&var1;
	printf("*p32(var1) = %08Xh\n", *p32);

	p32 = (int*)&var2;
	printf("*p32(var2) = %08Xh\n", *p32);

	p32 = (int*)&var3;
	printf("*p32(var3) = %08Xh\n", *p32);
}

void test2(void) {
	int var1 = 0x01020304;
	int *p32 = NULL;
	short* p16 = NULL;
	char* p8 = NULL;

	printf("Test 2 =============\n\n");

	printf("Address of var1 = %p\n", &var1);

	printf("Address of p32 = %p\n", &p32);
	printf("Address of p16 = %p\n", &p16);
	printf("Address of p8 = %p\n", &p8);

	printf("Value of p32 = %p\n", p32);
	printf("Value of p16 = %p\n", p16);
	printf("Value of p8 = %p\n", p8);

	p32 = (int*)&var1;
	p16 = (short*)&var1;
	p8 = (char*)&var1;

	printf("Value of p32 = %p\n", p32);
	printf("Value of p16 = %p\n", p16);
	printf("Value of p8 = %p\n", p8);

	printf("Ref value of p32 = %X\n", *p32);
	printf("Ref value of p16 = %X\n", *p16);
	printf("Ref value of p8 = %X\n", *p8);

	p16++;
	p8++;
	printf("p16++; p8++;\n");
	printf("Ref value of p16 = %X\n", *p16);
	printf("Ref value of p8 = %X\n", *p8);

	p8++;
	printf("p16++; p8++;\n");
	printf("Ref value of p8 = %X\n", *p8);

	p8++;
	printf("p16++; p8++;\n");
	printf("Ref value of p8 = %X\n", *p8);

}

int main()
{
	test1();

	test2();
}

