// Rule 110 is turnig complete, but it forms a /| triangle which is no good
// Rule 124 is the reflection of rule 110 so that it forms a |\ triangle, which is way better for printing
// This program models rule 124 and prints it to the screen
// and also I guess we can write it to a string file as well.

// the rules:	000	001	010	011	100	101	110	111		where 0 is white, 1 is black
//				 0   0   1   1   1   1   1   0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NUM_ROWS 100

void printTheRow(char *row)
{
	int i = 0;
	while ((row[i] == '0') || (row[i] == '1'))
	{
		if (row[i]=='1')
		{
			printf("1");
		} else if (row[i]=='0') {
			printf("0");
		}
		i++;
	}
	printf("\n");
}

int main(void)
{
	// so we intialise our string. This is the row above
	char upperRow[9998]="1";
	char lowerRow[9998]="1";
	
	// we need to print the string, and then make the string below. Many times
	int i, j;
	int state;
	for (i=1; i<NUM_ROWS; i++)									// this for loop just manages which line you are printing. Line 1 has 1 character etc.
	{															// when i is 2, uppperRow has 1, lowerRow has 2.
		printf("%d\t", i);
		//%s\n", i, upperRow);
		printTheRow(upperRow);
		
		for (j=0; j<i+1; j++)									// cycling through each digit in a row
		{
			state=0;
			if (upperRow[j-1] == '1')
			{
				state=state+4;
			}
			if (upperRow[j] == '1')
			{
				state=state+2;
			}
			if (upperRow[j+1] == '1')
			{
				state=state+1;
			}
			
			if ((state > 1) && (state < 7))
			{
				// printf("oh yeah")
				lowerRow[j]='1';
			} else
			{
				lowerRow[j]='0';
			}
		}
		
		
		
		
		
		
		
		
		/*
		printf("%s\n", upperRow);
		
		for (j=1; j<i; j++)									// this is the one that cycles through the digits
		{
			printf("\nj is %d\n", j);
			state = 0;
			lowerRow[0]='1';
			// updateTheLowerString(upperRow, lowerRow);
			if (upperRow[j-1] == '1')
			{
				state=state+4;
			}
			if (upperRow[j] == '1')
			{
				state=state+2;
			}
			if (upperRow[j+1] == '1')
			{
				state=state+1;
			}
			
			if ((state >= 2) && (state <= 6))
			{	
				lowerRow[j] = '1';
				printf("we hit the win condition \n");
			} else {
				lowerRow[j] = '0';
				printf("we hit the lose condition \n");
			}
		}
		
		
		
		
		/*
		printf("the %dth number is %c\n", i, upperRow[i]);
		
		if (upperRow[i]=='1')
		{
			printf("yeah this got a 1 bro\n");
		} else {
			printf("nah bro\n");
		}
		
		printf("\n");
		*/
		
		
		
		
		
		
		// we've updated the lower row, we can print it.
		// But more importantly, we've already printed the top row, and we've referenced it fully. We no longer need it.
		
		// makeTheLowerRowTheUpperRow()
		strcpy(upperRow, lowerRow);
	}
	
	return 0;
}