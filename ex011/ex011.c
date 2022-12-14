#include <stdio.h>

int main(int argc, char* argv[])
{
	char var1_1, var1_2, var1_3;
	char var3[10];
	int var2_1, var2_2, var2_3;
	
	short var4[3];
	int var5[5];
	long int var6[6];
	long long int var7[3];

	printf("sizeof(char) = %lld\n", sizeof(char));
	printf("sizeof(short) = %lld\n", sizeof(short));
	printf("sizeof(int) = %lld\n", sizeof(int));
	printf("sizeof(long int) = %lld\n", sizeof(long int));
	printf("sizeof(long long int) = %lld\n", sizeof(long long int));

	printf("sizeof(char *) = %lld\n", sizeof(char *));
	printf("sizeof(short *) = %lld\n", sizeof(short *));
	printf("sizeof(int *) = %lld\n", sizeof(int *));
	printf("sizeof(long int *) = %lld\n", sizeof(long int *));
	printf("sizeof(long long int *) = %lld\n", sizeof(long long int *));


	printf("Address of var1_1: %p\n", &var1_1);
	printf("Address of var1_2: %p\n", &var1_2);
	printf("Address of var1_3: %p\n", &var1_3);
	
	printf("Address of var2_1: %p\n", &var2_1);
	printf("Address of var2_2: %p\n", &var2_2);
	printf("Address of var2_3: %p\n", &var2_3);

	printf("Address of var3: %p\n", var3);
	printf("Address of &var3[0]: %p\n", &var3[0]);
	printf("Address of var3+1: %p\n", var3+1);
	printf("Address of &var3[1]: %p\n", &var3[1]);

	printf("Address of var4: %p\n", var4);
	printf("Address of &var4[0]: %p\n", &var4[0]);
	printf("Address of var4+1: %p\n", var4 + 1);
	printf("Address of &var4[1]: %p\n", &var4[1]);

	printf("Address of var5: %p\n", var5);
	printf("Address of &var5[0]: %p\n", &var5[0]);
	printf("Address of var5+1: %p\n", var5 + 1);
	printf("Address of &var5[1]: %p\n", &var5[1]);

	printf("Address of var6: %p\n", var6);
	printf("Address of &var6[0]: %p\n", &var6[0]);
	printf("Address of var6+1: %p\n", var6 + 1);
	printf("Address of &var6[1]: %p\n", &var6[1]);

	printf("Address of var7: %p\n", var7);
	printf("Address of &var7[0]: %p\n", &var7[0]);
	printf("Address of var7+1: %p\n", var7 + 1);
	printf("Address of &var7[1]: %p\n", &var7[1]);
	 
	int d32;
	short d16;
	char d8;

	d32 = 0xFEDCBA98;
	d16 = (short)d32;
	d8 = (char)d32;

	printf("d32 = %Xh, d16 = %Xh, d8 = %Xh\n", d32, d16, d8);
	printf("d32 = %Xh, d16 = %hXh, d8 = %hhXh\n", d32, d16, d8);
	printf("d32 = %d, d16 = %d, d8 = %d\n", d32, d16, d8);

	return 1;
}

