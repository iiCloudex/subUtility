/**
 * Name: Marco Antonio Bustamante
 * Lab/Task: Lab 2/ Task 1
 * Date: 09/06/18 
 * 
 **/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Description: 
// This function opens the help file and
// prints it to the screen.
void helpPrompt()
{
	FILE *help;
	char c;
	
	//Open help.txt
	help = freopen("help.txt", "r", stdin); 
	
	if(help)
	{	
		while( (c = getc(help)) != EOF)
		{	
			fputc(c, stdout);
		}
	
		fclose(help);
		exit(0);
	}

}


// Description:
// This function takes an input file and replaces
// every character that is also in toRepl with the
// corresponding character in isRepl then prints it
// to the output file.
void replace(char *toRepl, char *isRepl, FILE *input, FILE *output)
{
	FILE *ir;
	FILE *or;
	int index;
	int minSearch = strlen(toRepl);
	char *i;

	//Find the minimum value to search for
	if(strlen(isRepl) < minSearch)
	{
		minSearch = strlen(isRepl);
	}

	ir = freopen(input, "r", stdin);
	or = freopen(output, "w", stdout);

	while( (i = getc(ir)) != EOF) //go char by char
	{	
		index = -1; //-1 for not found

		//search if i is in toRepl
		for(int j = 0; j < strlen(toRepl) && j < minSearch; j++)
		{
			//if it is then grab the index
			if( toRepl[j] == i)
			{
				index = j;
			}
		}
		
		//if found replace it
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
		userInput = argv[i]; //grab first string
		
		switch(userInput[1])
		{
			case '-':
				//Set variable
				toRepl = userInput + 2;	
				break;
			case '+':
				//Set variable
				isRepl = userInput +2;
				break;
			case 'i':
				//Set input file
				i++;
				inputFile = argv[i];
				break;
			case 'o':
				//Set output file
				i++;
				outputFile = argv[i];
				break;
			case 'h':
				//print help	
				helpPrompt();
				break;
			default:
				//Error
				printf("misuse of the sub utility\n");
				printf("type sub -h for help\n");
				exit(1);
				break;
		}

	}

	replace(toRepl, isRepl, inputFile, outputFile);

	return 0;	
}


