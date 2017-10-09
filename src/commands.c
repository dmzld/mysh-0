#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include "commands.h"



int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
		
  char* buff=(char*)malloc(sizeof(char)*1024);
  int i=0; 

  if(!strcmp(".",argv[1])){
  	return 0;
  }
  else if(!strcmp("..",argv[1])){
  		
	if(!strcmp(buff,"/home")){
	chdir("/");
	}
	else{
	getcwd(buff,1024);
	char* upper = strrchr(buff,'/');
	*upper = '\0';
	chdir(buff);
	}

  }
  else if(!strcmp("/",argv[1])){
  	chdir("/");
  }
  else if(!strcmp("~",argv[1])){
  	chdir("/home/aeis");
  }
  else if(argv[1]==NULL){
    return -1;
  }
  else{
  chdir(argv[1]);// if command cd ~ -> cd in [0], all of ~ in [1]
  }
  return 0;
}


int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))//in 1 -> pass
    return -1;
	
  char* buff=(char*)malloc(sizeof(char)*1024);
  getcwd(buff,1024);
  printf("%s\n",buff);
 	
  free(buff);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc==1)
  	return 0;
  
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc>1 || strcmp(argv[0],"pwd")){
  	return 0;
  }

  return 1;
}
