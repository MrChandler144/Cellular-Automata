#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM 10

// just takes in a base-ten int and produces a string of the binary representation of that number
// only goes up to I think 2^15 maybe because that's excessive

int main(void)
{
	int num = -1;
	int numDigits;
	char binary[15]="0";
	
	// read in a number and find the number of digits
	while (num < 0)
	{
		printf("Number? ");
		scanf("%d", &num);
		if (num == 0)
		{
			numDigits=1;
		} else {
			// figure out how many digits
			numDigits = (log(num) / log(2)) + 1;	// so 3 returns 2 digits, and 4 returns 3 digits
		}
	}
	// printf("the number is %d and the number of digits is %d", num, numDigits);
	
	// 1	2	4	8	16	32	64
	// 1	2	3	4	5	6	7
	
	// printf("log2 (34) is %f\n", (log(34)/log(2)));
	
	
	// now we do the maths
	int i=0;
	for (i=0; i<numDigits; i++)
	{
		if (num%2 == 1)
		{
			binary[i]='1';
		} else {
			binary[i]='0';
		}
		num=num/2;
	}
	_strrev(binary);
	printf("and for the fun of it, the number is %s", binary);
	
	return 0;
}