// Rule 110 is turnig complete, but it forms a /| triangle which is no good
// Rule 124 is the reflection of rule 110 so that it forms a |\ triangle, which is way better for printing
// This program models rule 124 and prints it to the screen
// and also I guess we can write it to a string file as well.

// the rules:	000	001	010	011	100	101	110	111		where 0 is white, 1 is black
//				 0   0   1   1   1   1   1   0

// 195 is unreasonably cool (inverse of 60)

// TODO:
// if we know it won't fly off to the side don't add digits there
// ask for seed

// v2 starts to handle it as just one long string that we print off at the end
// v3 makes a dynamic interpretation of which rule to use so we can change which rule we want
// v4 makes it a square display. You enter your start seed at the start of the main function,
	// we add padding on either side according to how many rows you want,
	// and it iterates down. also the first line is broken
// v5 makes it a grid by rewriting the entire main function I guess

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_ROWS 50
#define RULE 124

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
	
	// now pad up to eight numbers
	for (i=0; i<(8-numDigits); i++)
	{
		binary[i+numDigits]='0';
	}
	
	//_strrev(binary);
	//binary[8]='\0';
	//printf("and for the fun of it, the number is %s\n", binary);
}

void goInflateTheUpperRow(char *upperRow, int *length)
{
	// so this one is passed a string
	// what we need to do is pad it out
	// so add zeros before and after so that we don't hit the walls in our expression
	int num = NUM_ROWS + 2;
	//printf("num is %d \n", num);
	
	// we'll use strcat
	char blanks[2000]="0";
	int i;
	for (i=0; i<num; i++)
	{
		blanks[i]='0';
	}
	blanks[num]='\0';
	// printf("the blanks are %s\n", blanks);
	strcat(upperRow, blanks);
	strcat(blanks, upperRow);
	
	strcpy(upperRow, blanks);
	/*
	// figure out how many letters (actually my first time using strlen() wow)
	int length = (int)strlen(upperRow);
	
	int i;
	for (i=0; i<num; i++)
	{
		insertChar(upperRow, '0', length);
	}
	for (i=0; i<num; i++)
	{
		insertChar(upperRow, '0', 0);
	}
	*/
	
	// and also how long is this top line?
	*length = strlen(upperRow);
	
	//printf("the top row has %d different numbers\n", *length);
	
	//printf("so the top row is:\n%s\n", upperRow);
	
	//printf("\nBalloon pumped\n\n");
	
	
	//printf("the length in inflate function is %d. Num is %d and num rows is %d\n", length, num, NUM_ROWS);
}

void printTheString(char *row)
{
	
	int i = 0;
	while (row[i] != 0)
	{
		if (row[i]=='1')
		{
			printf("X");
		} else if (row[i]=='0') {
			printf(".");
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
	char upperRow[9998]="1000000000000001";									// edit here to change the seed
	char lowerRow[9998];
	char theString[9998];
	char binary[10]="abcd fgh";
	makeTheBinary(RULE, binary);
	
	// figure out how wide we are
	int length = 0;
	goInflateTheUpperRow(upperRow, &length);
	//printf("the length value is %d.\n", length);
	
	strcpy(theString, upperRow);
	insertChar(theString, '\n', length);
	
	// we need to print the string, and then make the string below. Many times
	// v2 edit: since we are adding it to one string, we can actually still process it on two
	// different strings, but just add to the end when we're done
	
	int i, j;
	int state;
	for (i=1; i<NUM_ROWS; i++)									// this for loop just manages which line you are handling. Line 1 is the first line etc
	{
		//printf("%d\t", i);
		//%s\n", i, upperRow);
		
		lowerRow[0]='X';
		for (j=1; j<length-1; j++)								// cycling through each digit in a row
		{
			//get the state of the above things
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
		lowerRow[0]=lowerRow[1];
		lowerRow[length-1]=lowerRow[length-2];
		lowerRow[length]='\n';
		
		
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
		theString[k/*+1*/]='\0';
		
		//strcat(theString, '\n');
		
		
		strcat(theString, lowerRow);
	}

	printTheString(theString);
	
	return 0;
}