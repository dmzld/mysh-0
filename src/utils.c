#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	*argv = (char**)malloc(sizeof(char)*100);//3-1=2
	//char* token = malloc(sizeof(char)*100);
	*argc = 0;
	

	char str[100];


	strcpy(str, command);

	char* token = strtok(str," ");

	while(token != NULL)
	{
		(*argv)[*argc]=(char*)malloc(sizeof(char)*100);
		strcpy((*argv)[*argc],token);
		(*argc)++;
		
		token = strtok(NULL," ");
	}

	

}
