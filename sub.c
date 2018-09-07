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
				break;
			case '+':
				//Set variable
				isRepl = userInput + 2;
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
				printf("error\n");
				break;
		}

	}

	return 0;			
}


