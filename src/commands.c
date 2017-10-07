#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "commands.h"


// !1 == 0  == true
int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
	
  char buff[1024];
  getcwd(buff,1024);
  printf("%s\n",buff);
 	

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  char* str1;
  strcpy(str1,*argv);
  char* str2 = "cd";
  if(!strcmp(str1,str2)) return 0;
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  char* str1;
  strcpy(str1,*argv);
  char* str2 = "pwd";
  if(!strcmp(str1,str2)) return 0;
  return 1;
}
