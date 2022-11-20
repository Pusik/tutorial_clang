#include <stdio.h>
#include <math.h>
#include <float.h>

// Floating Point Number
// Size of primary data type
// float(4):	3.4E-38 to 3.4E+38	
// double(8):	1.7E-308 to 1.7E+308

// In a computer system, the IEEE-754 format represents the floating-point numbers.A majority of modern processors and processors adopt this format.
// It has two major representations :
// 1. 32-bit single precision 
// 2. 64-bit double precision

//The representation of the floating numbers has further classifications.These are :
//
//1. The Normalised Form
//   We will take a look at an example to understand this better.
//   Assume that the 32-bit type of pattern is
//
//   1 1000 0001 011 0000 0000 0000 0000 0000, where:
//
//   1 bit: sign bit
//   8 bits: exponent p
//   23 bits : mantissa
// 
//   S = 1
//   E = 1000 0001
//   F = 011 0000 0000 0000 0000 0000
//
//   In a normalised form, the mantissa or the actual fraction is normalised using an implicit that leads 1, which is in the form of 1.F.
//   For instance, in the example mentioned here, the actual fraction would be 1.011 0000 0000 0000 0000 0000 = 1 + 1×2^(-2) + 1×2^(-3) = 1.375D.
//   Here, the sign bit basically represents the number’s sign, where S = 1 is a negative number and S = 0 is a positive number.
//   In the example mentioned above, the S = 1. Thus, the number is negative. It means that the number would be - 1.375D.
//
//   The actual exponent in the normalised form would be E-127 (it is the so-called bias-127 or excess-127).
//   It is because a person needs to represent both negative and positive exponents.
//   In the case of an 8-bit E that ranges from 0 to 255, the actual exponent of the numbers -127 to 128 could be provided by the excess-127 scheme.
//   For instance, in the mentioned example, E-127 = 129 - 127 = 2D.
//
//
//   2. The De-Normalised Form
//   The normalised form has some serious problems.
//   For instance, it uses an implicit that leads 1 for a fraction.Thus, the normalised form cannot represent zero as a number that would start with 1. 
//   The de-normalised form is basically devised for representing the number zero as well as the other numbers.
//   These numbers are in a de-normalised form for the E = 0. 
//   An implicit that leads 0 and not 1 would be used for a fraction.
//   The actual exponent here is always -126. Thus, we can represent the number 0 using an F = 0 and an E = 0, because 0.0×2^(-126) = 0.
//
//   A person can easily represent very small negative and positive numbers in a de-normalised form using an E = 0. 
//   For instance, if F = 011 0000 0000 0000 0000 0000, E = 0, and S = 1, the actual fraction would be 0.011 = 1×2^(-2) + 1×2^(-3) = 0.375D.
//   Now since S = 1, the given number is actually negative.
//   Now with E = 0, -126 would be the actual exponent.
//   Thus, the number here is -0.375 × 2^(–126) = -4.4×10^(–39). 
//   Now, this is an extremely small number that is negative(very close to the number 0).

//   Summary:
//   The calculation of the value N would be :
//
//   (a) For 1 ≤ E ≤ 254, N = (-1)^S × 1.F × 2^(E-127).
//
//   The numbers here are in a normalised form.The sign of the number here is represented by the sign-bit.
//   The implicit that leads 1 normalises the fractional part, that is 1.F.
//   The exponent here is in excess(or bias) of 127 for representing both negativeand positive exponents.
//   The overall range of the exponents here would be -126 to +127.
//
//   (b)In the case of E = 0, N = (-1)^S × 0.F × 2^(-126).
//
//   All of these numbers are in the de-normalised form. 
//   Thus, the exponent of the value 2 ^(-126) would then evaluate as a number that is very small.
//   We need to represent the denormalised form using E = 0 and F = 0. 
//   These can also represent extremely negative and positive numbers that are close to the value of zero.
//
//   (c)In the case of E = 255, some special values would be represented, for instance, NaN(it refers to not a number) and ±INF(the negative and positive infinity).


float float_from_bytes(unsigned int	sign, unsigned int	exponent, unsigned int	fraction) 
{
	unsigned int	bytes;

	bytes = 0;
	bytes |= sign;
	bytes <<= 8;
	bytes |= exponent;
	bytes <<= 23;
	bytes |= fraction;
	
	return *(float*)&bytes;
}

typedef union {
	float	f;
	int	i;
} Number;

void ASSERT(int b)
{
    if (!b) {
        printf("FALSE, ASSERTED!\n");
    }
}

int main(int argc, char* argv[])
{
    /* All 1 exponent and non-0 fraction means NaN.
     * There are of course many possible representations,
     * and some have special semantics such as signalling vs not.
     */
    ASSERT(isnan(float_from_bytes(0, 0xFF, 1)));
    ASSERT(isnan(NAN));
    printf("nan                  = %e\n", NAN);

    /* All 1 exponent and 0 fraction means infinity. */
    ASSERT(INFINITY == float_from_bytes(0, 0xFF, 0));
    ASSERT(isinf(INFINITY));
    printf("infinity             = %e\n", INFINITY);

    /* ANSI C defines FLT_MAX as the largest non-infinite number. */
    ASSERT(FLT_MAX == 0x1.FFFFFEp127f);
    /* Not 0xFF because that is infinite. */
    ASSERT(FLT_MAX == float_from_bytes(0, 0xFE, 0x7FFFFF));
    ASSERT(!isinf(FLT_MAX));
    ASSERT(FLT_MAX < INFINITY);
    printf("largest non infinite = %e\n", FLT_MAX);

    /* ANSI C defines FLT_MIN as the smallest non-subnormal number. */
    ASSERT(FLT_MIN == 0x1.0p-126f);
    ASSERT(FLT_MIN == float_from_bytes(0, 1, 0));
    ASSERT(isnormal(FLT_MIN));
    printf("smallest normal      = %e\n", FLT_MIN);

    /* The smallest non-zero subnormal number. */
    float smallest_subnormal = float_from_bytes(0, 0, 1);
    ASSERT(smallest_subnormal == 0x0.000002p-126f);
    ASSERT(0.0f < smallest_subnormal);
    ASSERT(!isnormal(smallest_subnormal));
    printf("smallest subnormal   = %e\n", smallest_subnormal);

	return 1;
}

