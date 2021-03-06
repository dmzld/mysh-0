#include "utils.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{   
	*argv = (char**)malloc(sizeof(char)*1024);//3-1=2
	*argc = 0;

	
	char* str = (char*)malloc(sizeof(char)*1024);
	strcpy(str, command);
	
	char* token = strtok(str," ");
	
	while(token != NULL){
	
		if((strcmp(token,"\t")!=0)&&(strcmp(token,"\n"))!=0){
			
			(*argv)[*argc] = (char*)malloc(sizeof(char)*1024);
			strcpy((*argv)[*argc],token);
	
			(*argc)++;		
		}
		token = strtok(NULL," ");
	}
	
	if((*argc)==0){
		(*argv)[*argc] = (char*)malloc(sizeof(char)*1024);
		strcpy((*argv)[*argc],"");
		(*argc)++;
		}
	
	else if((*argc)>=1){
		(*argv)[*argc]=NULL;
	
	//remove '\n'
		char* last = strtok((*argv)[(*argc)-1],"\n");
		strncpy((*argv)[(*argc)-1],last,sizeof(last)-1);
		
	}
	
	free(str);
	
}
