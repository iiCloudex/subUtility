/**
 * Name: Marco Antonio Bustamante
 * Lab/Task: Lab 2/ Task 1
 * Date: 09/06/18 
 * 
 **/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helpPrompt()
{
	FILE *help;
	char c;

	help = freopen("help.txt", "r", stdin);
	
	while( (c = getc(help)) != EOF)
	{
		fputc(c, stdout);
	}
	
	fclose(help);
	
}

void replace(char *toRepl, char *isRepl, FILE *input, FILE *output)
{
	FILE *ir;
	FILE *or;
	int index;
	int minSearch = strlen(toRepl);
	char *i;

	if(strlen(isRepl) < minSearch)
	{
		minSearch = strlen(isRepl);
	}

	ir = freopen(input, "r", stdin);
	or = freopen(output, "w", stdout);

	while( (i = getc(ir)) != EOF)
	{	
		index = -1;
		for(int j = 0; j < strlen(toRepl) && j < minSearch; j++)
		{
			if( toRepl[j] == i)
			{
				index = j;
			}
		}
		
		if(index >= 0 && isRepl[index] != EOF)
		{
			fputc(isRepl[index], or);
		}
		else
		{
			fputc(i, or);
		}
	}
	fclose(ir);
	fclose(or);	

}



int main(int argc, char **argv)
{
	char *userInput;
	char *toRepl = NULL;
	char *isRepl = NULL;
	FILE *inputFile = NULL;
	FILE *outputFile = NULL;
	

	for(int i = 1; i < argc; i++)
	{
		userInput = argv[i];
		
		switch(userInput[1])
		{
			case '-':
				//Set variable
				toRepl = userInput + 2;
				printf("replacing: %s\n", toRepl);
				break;
			case '+':
				//Set variable
				isRepl = userInput + 2;
				printf("with: %s\n", isRepl);
				break;
			case 'i':
				//Set input file
				i++;
				inputFile = argv[i];
				printf("input file: %s\n", inputFile);
				break;
			case 'o':
				//Set output file
				i++;
				outputFile = argv[i];
				printf("output file: %s\n", outputFile);
				break;
			case 'h':
				//print help	
				helpPrompt();
				break;
			default:
				//Error
				printf("misuse of the sub utility\n");
				printf("type sub -h for help\n");
				break;
		}

	}

	replace(toRepl, isRepl, inputFile, outputFile);

	return 0;	
}


