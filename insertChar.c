#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


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

int main(void)
{
	char story[100] = "Text";
	insertChar(story, 'a', 2);
	
	printf("%s", story);
	
	return 0;
}