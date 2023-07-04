// This program model's Wolfram's Cellular Automata

// the rules:	000	001	010	011	100	101	110	111		where 0 is white, 1 is black
//				 0   0   1   1   1   1   1   0

// v2 starts to handle it as just one long string that we print off at the end
// v3 makes a dynamic interpretation of which rule to use so we can change which rule we want
// v4 makes it a square display. You enter your start seed at the start of the main function,
	// we add padding on either side according to how many rows you want,
	// and it iterates down. also the first line is broken
// v5 makes it a grid by rewriting the entire main function I guess
// v6 makes it so that if the function isn't going to go to the left or right, it doesn't add so many there
// v7 asks for a rule seed and displays it ad infinitum
// v8 displays zeros as empty space whereas v7 displays full stops
// production version adds a flashy new intro

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define NUM_ROWS 50


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
		numDigits = (int)((log(num) / log(2)) + 1);	// so 3 returns 2 digits, and 4 returns 3 digits
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
}

void goInflateTheUpperRow(char *upperRow, int *length, char *binary, int rule)
{
	// so this one is passed a string
	// what we need to do is pad it out
	// so add zeros before and after so that we don't hit the walls in our expression
	int num = NUM_ROWS + 1;
	
	// we'll use strcat
	char blanks[65535]="0";
	char blanks2[65535]="00";
	int i;
	for (i=0; i<num; i++)
	{
		blanks[i]='0';
	}
	
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
	
	// this one adds the cells to the left
	if (rule%4 != 0)
	{
		// we hit the condition
		strcat(blanks, upperRow);
		strcpy(upperRow, blanks);
	} else {
		// we do not hit the condition
		blanks[0]='0';
		blanks[1]='0';
		blanks[2]='\0';
		strcat(blanks, upperRow);
		strcpy(upperRow, blanks);
	}
	
	
	// and also how long is this top line?
	*length = strlen(upperRow);
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
			printf(" ");
		} else if (row[i]=='\n') {
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void runTheFlashyIntro(void)
{
	printf("Ladies and gentlemen, boys and girls...\n");
	
	clock_t currentTime = clock();
	clock_t newTime;
	double elapsedTime = 0;
	
	while (elapsedTime <3000)
	{
		newTime = clock();
		elapsedTime = (newTime - currentTime) * 1000 / CLOCKS_PER_SEC;
	}
	printf("It is my absolute pleasure to present to you...\n");
	currentTime = clock();
	elapsedTime = 0;
	while (elapsedTime <3000)
	{
		newTime = clock();
		elapsedTime = (newTime - currentTime) * 1000 / CLOCKS_PER_SEC;
	}
	printf("A beginner's guide to...\n");
	currentTime = clock();
	elapsedTime = 0;
	while (elapsedTime <2900)
	{
		newTime = clock();
		elapsedTime = (newTime - currentTime) * 1000 / CLOCKS_PER_SEC;
	}
	printf("\n"
	"      _                           _                            \n"
	"     | |                         | |                           \n"
	"  ___| | ___ _ __ ___   ___ _ __ | |_ __ _ _ __ _   _          \n"
	" / _ \\ |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __/ _` | '__| | | |         \n"
	"|  __/ |  __/ | | | | |  __/ | | | || (_| | |  | |_| |         \n"
	" \\___|_|\\___|_| |_| |_|\\___|_| |_|\\__\\__,_|_|   \\__, |         \n"
	"         | | |     | |                           __/ |         \n"
	"  ___ ___| | |_   _| | __ _ _ __                |___/          \n"
	" / __/ _ \\ | | | | | |/ _` | '__|                              \n"
	"| (_|  __/ | | |_| | | (_| | |                                 \n"
	" \\___\\___|_|_|\\__,_|_|\\__,_|_|        _          _             \n"
	"            | |                      | |        | |            \n"
	"  __ _ _   _| |_ ___  _ __ ___   __ _| |_ __ _  | |            \n"
	" / _` | | | | __/ _ \\| '_ ` _ \\ / _` | __/ _` | | |            \n"
	"| (_| | |_| | || (_) | | | | | | (_| | || (_| | |_|            \n"
	" \\__,_|\\__,_|\\__\\___/|_| |_| |_|\\__,_|\\__\\__,_| (_)  			\n\n\n");
	// with credit to https://patorjk.com/software/taag/#p=display&f=Big&t=
	
	currentTime = clock();
	elapsedTime = 0;
	while (elapsedTime <4000)
	{
		newTime = clock();
		elapsedTime = (newTime - currentTime) * 1000 / CLOCKS_PER_SEC;
	}
}

int main(void)
{
	runTheFlashyIntro();
	
	// so we intialise our string. This is the row above
	int i, j, k, length;
	int rule = -1;
	int ruleCount = 0;
	char seed[65535] = "1";									// edit here to change the seed.
	char binary[10]="abcd fgh";
	// now run the loop. It does not terminate.
	while (1)
	{
		char upperRow[65535]="1";
		char lowerRow[65535];
		char theString[65535];
		strcpy(upperRow, seed);
		printf("Rule?\n");
		scanf("%d", &rule);
		
		while ((rule <0) || (rule > 255))
		{
			if (ruleCount != 2)
			{
			printf("\n"
			"  _                                  _         \n"
			" | |                                (_)        \n"
			" | |_ _ __ _   _    __ _  __ _  __ _ _ _ __    \n"
			" | __| '__| | | |  / _` |/ _` |/ _` | | '_ \\   \n"
			" | |_| |  | |_| | | (_| | (_| | (_| | | | | |_ \n"
			"  \\__|_|   \\__, |  \\__,_|\\__, |\\__,_|_|_| |_( )\n"
			"  _         __/ | _   _   __/ |             |/ \n"
			" | |       |___/ | | | | |___/                 \n"
			" | |__  _   _  __| | | |                       \n"
			" | '_ \\| | | |/ _` | | |                       \n"
			" | |_) | |_| | (_| | |_|                       \n"
			" |_.__/ \\__,_|\\__,_| (_)                       \n\n");
			} else {
				// an easter egg
				printf("\n"
				" _           _ \n"
				"| |         (_)\n"
				"| |__   ___  _ \n"
				"| '_ \\ / _ \\| |\n"
				"| |_) | (_) | |\n"
				"|_.__/ \\___/|_|\n\n");
			}
			ruleCount++;
			scanf("%d", &rule);
		}
		ruleCount=0;

		makeTheBinary(rule, binary);
		
		// figure out how wide we are
		length = 0;
		goInflateTheUpperRow(upperRow, &length, binary, rule);
		
		strcpy(theString, upperRow);
		strcpy(lowerRow, upperRow);
		insertChar(theString, '\n', length);
		
		// we need to print the string, and then make the string below. Many times
		// v2 edit: since we are adding it to one string, we can actually still process it on two different strings, but just add to the end when we're done
	
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
			
			// make the lower row the upper row
			strcpy(upperRow, lowerRow);
			
			// gotta add the new line to our printing string
			k=k+length+1;
			theString[k]='\n';
			theString[k]='\0';
			
			strcat(theString, lowerRow);
		}

		theString[k]='\0';
		printTheString(theString);
		
	}
	
	return 0;
}