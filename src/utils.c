#include "utils.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{   
	*argv = (char**)malloc(sizeof(char)*1024);//3-1=2
	*argc = 0;
	

	char str[1024];
	

	strcpy(str, command);

	char* token = strtok(str," ");

	while(token != NULL)
	{
		(*argv)[*argc]=(char*)malloc(sizeof(char)*1024);//3-2=1
		
		strcpy((*argv)[*argc],token);
		(*argc)++;
		
		token = strtok(NULL," ");
	}
	
	(*argc)--;
	//remove '\n'
	char* last = strtok((*argv)[*argc],"\n");
	strncpy((*argv)[*argc],last,sizeof(last)-1);
	

}
