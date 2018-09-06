/**
 * Name: Marco Antonio Bustamante
 * Lab/Task: Lab 2/ Task 1
 * Date: 09/06/18 
 * 
 **/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv)
{
	char *userInput;
	char *toRepl;
	char *isRepl;


	for(int i = 1; i < argc; i++)
	{
		userInput = argv[i];
		
		switch((int) userInput[1])
		{
			case (int)'-':
				//Set variable
				printf("needs to be replaced\n");
				break;
			case (int)'+':
				//Set variable
				printf("going to replace\n");
				break;
			case (int)'i':
				//Set input file
				printf("input file\n");
				break;
			case (int)'o':
				//Set output file
				printf("output file\n");
				break;
			case (int)'h':
				//print help
				printf("help\h");
				break;
			default:
				//Error
				printf("error\n");
				break;
		}

	}

	return 0;			
}


