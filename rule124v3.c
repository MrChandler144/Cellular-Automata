// Rule 110 is turnig complete, but it forms a /| triangle which is no good
// Rule 124 is the reflection of rule 110 so that it forms a |\ triangle, which is way better for printing
// This program models rule 124 and prints it to the screen
// and also I guess we can write it to a string file as well.

// the rules:	000	001	010	011	100	101	110	111		where 0 is white, 1 is black
//				 0   0   1   1   1   1   1   0

// TODO:
// start seed longer than one digit

// v2 starts to handle it as just one long string that we print off at the end
// v3 makes a dynamic interpretation of which rule to use so we can change which rule we want

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_ROWS 100
#define RULE 158

void insertChar(char *string, char letter, int index)
{
	// adds the 'letter' into 'string' at position 'index'
	// doesn't even need the length leshgo
	int i = index;
	char memoryplace = letter;
	char memorytake = string[i];
	while (string[i-1] != '\0')
	{
		memorytake=string[i];
		string[i]=memoryplace;
		memoryplace=memorytake;
		i++;
	}
}

void makeTheBinary(int num, char *binary)
{
	int numDigits;
	
	if (num == 0)
	{
		numDigits=1;
	} else {
		// figure out how many digits
		numDigits = (log(num) / log(2)) + 1;	// so 3 returns 2 digits, and 4 returns 3 digits
	}

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
	// now uh eight numbers
	
	for (i=0; i<(8-numDigits); i++)
	{
		binary[i+numDigits]='0';
	}
	//_strrev(binary);
	//binary[8]='\0';
	printf("and for the fun of it, the number is %s\n", binary);
}

void printTheString(char *row)
{
	
	int i = 0;
	while ((row[i] == '0') || (row[i] == '1') || row[i] == '\n')
	{
		if (row[i]=='1')
		{
			printf("x");
		} else if (row[i]=='0') {
			printf(" ");
		} else if (row[i]=='\n') {
			printf("\n");
		}
		i++;
	}
	printf("\n");
	
	//printf("%s", row);
}

int main(void)
{
	// so we intialise our string. This is the row above
	char upperRow[9998]="1";
	char lowerRow[9998];//="1";
	char theString[9998]="1";
	char binary[10]="abcd fgh";
	strcpy(theString, upperRow);
	makeTheBinary(RULE, binary);
	
	
	// we need to print the string, and then make the string below. Many times
	// v2 edit: since we are adding it to one string, we can actually still process it on two
	// different strings, but just add to the end when we're done
	
	int i, j;
	int state;
	for (i=1; i<NUM_ROWS; i++)									// this for loop just manages which line you are printing. Line 1 has 1 character etc.
	{															// when i is 2, uppperRow has 1, lowerRow has 2.
		//printf("%d\t", i);
		//%s\n", i, upperRow);
		
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
			
			//if ((state > 1) && (state < 7))
				// we also reversed the final number for this to work
			if (binary[state] == '1')
			{
				// printf("oh yeah")
				lowerRow[j]='1';
			} else
			{
				lowerRow[j]='0';
			}
		}
		// hey it works
		
		
		// we've updated the lower row, we can print it.
		// But more importantly, we've already printed the top row, and we've referenced it fully. We no longer need it.
		
		// makeTheLowerRowTheUpperRow()
		strcpy(upperRow, lowerRow);
		
		// gotta add the new line to our printing string
		int k = 0;
		while (theString[k] != '\0')
		{
			k++;
		}
		theString[k]='\n';
		theString[k+1]='\0';
		
		//strcat(theString, '\n');
		
		
		strcat(theString, lowerRow);
	}

	printTheString(theString);
	
	return 0;
}