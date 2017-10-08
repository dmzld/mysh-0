#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "commands.h"


// !1 == 0  == true
int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
 
  char buff[1024];
  int i=0;

  if(strcmp(".",argv[1])){
  	return 0;
  }
  else if(strcmp("..",argv[1])){
  	getcwd(buff,1024);
	// tokenize at last / 
  }
  else if(strcmp("/",argv[1])){
  	chdir("/");
  }
  else if(strcmp("~",argv[1])){
  	chdir("/home");
  }
  else{
  chdir(argv[1]);// if command cd ~ -> cd in [0], all of ~ in [1]
  }
  return 0;
}

//0 == fales --> !0 == true
int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))//in 1 -> pass
    return -1;
	
  char buff[1024];
  getcwd(buff,1024);
  printf("%s\n",buff);
 	

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  int i;

  for(i=0; i==argc; i++){
  	if(sizeof(argv[i])!=0){
		return 0;
	}
  }
  return 1;//correct
}

int validate_pwd_argv(int argc, char** argv) {
  if(argv[1]!=NULL){
  	return 0;
  }
  
  return 1;
}
