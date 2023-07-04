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
// v6 makes it so that if the function isn't going to go to the left or right, it doesn't add so many there
// v7 asks for a rule seed and dispolays it ad infinitum

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_ROWS 50
#define RULE 110

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

void goInflateTheUpperRow(char *upperRow, int *length, char *binary, int rule)
{
	// so this one is passed a string
	// what we need to do is pad it out
	// so add zeros before and after so that we don't hit the walls in our expression
	int num = NUM_ROWS + 1;
	//printf("num is %d \n", num);
	
	// we'll use strcat
	char blanks[9998]="0";
	char blanks2[9998]="00";
	int i;
	for (i=0; i<num; i++)
	{
		blanks[i]='0';
	}
	//blanks[num]='\0';
	// printf("the blanks are %s\n", blanks);
	
	
	// this one adds the cells to the the right
	// the number is 01110111
	// so if zero and four index of binary is a zero then don't add
	if (!((binary[0] =='0') && (binary[4] == '0')))
	{
		strcat(upperRow, blanks);
	} else {
		// add some paddng at the end
		strcat(upperRow, blanks2);
	}
	
	// thiss one adds the cells to the left
	if (rule%4 != 0)
	{
		//printf("we hit the condition\n");
		strcat(blanks, upperRow);
		strcpy(upperRow, blanks);
	} else {
		//printf("we do not hit the condition\n");
		blanks[0]='0';
		blanks[1]='0';
		blanks[2]='\0';
		strcat(blanks, upperRow);
		strcpy(upperRow, blanks);
	}
	
	
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

void resetTheStrings(char *seed, char *upperRow, char *lowerRow, char *theString)
{
	int i;
	for (i=1; i<9997; i++)
	{
		upperRow[i]='0';
		lowerRow[i]='0';
		theString[i]='0';
	}
	strcpy(upperRow, seed);
	upperRow[0]='1';
	lowerRow[0]='1';
	theString[0]='1';
}

int main(void)
{
	// so we intialise our string. This is the row above
	int i, j, k, rule, length;
	char seed[9998] = "1";
	char binary[10]="abcd fgh";
	while (1)
	{
		char upperRow[9998]="1";									// edit here to change the seed
		char lowerRow[9998];
		char theString[9998];
		//resetTheStrings(seed, upperRow, lowerRow, theString);
		strcpy(upperRow, seed);
		printf("Rule?\n");
		scanf("%d", &rule);

		makeTheBinary(rule, binary);
		
		// figure out how wide we are
		length = 0;
		goInflateTheUpperRow(upperRow, &length, binary, rule);
		//printf("the length value is %d.\n", length);
		
		strcpy(theString, upperRow);
		strcpy(lowerRow, upperRow);
		insertChar(theString, '\n', length);
		
		//printf("so the top row is:\n%s\n", upperRow);
		//printf("et the low row is:\n%s\n", lowerRow);
		
		// we need to print the string, and then make the string below. Many times
		// v2 edit: since we are adding it to one string, we can actually still process it on two
		// different strings, but just add to the end when we're done
	
		int state;
		k = 0;
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
			/*while (theString[k] != '\0')
			{
				k++;
			}*/
			k=k+length+1;
			theString[k]='\n';
			theString[k]='\0';
			
			//strcat(theString, '\n');
			
			
			strcat(theString, lowerRow);
		}

		theString[k]='\0';
		printTheString(theString);
		
	}
	
	return 0;
}