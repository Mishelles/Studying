/***********************************************************
******Linux course on Stepik. Module 3. Task 6.
-----------------------------------------------------------
******Program to create a simple deamon in Linux
******Returns deamon's PID
------------------------------------------------------------
******Created by Mikhail Sergeenkov on 1th of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,const char* argv[]) {
  int pid = fork();
  switch(pid) {
    case 0:
      setsid();
      chdir("/");
      close(STDIN_FILENO);
      close(STDOUT_FILENO);
      close(STDERR_FILENO);
      sleep(10);
      exit(0);
    case -1:
      printf("Fail: unable to fork\n");
      break;
    default:
      printf("OK: demon with pid %d is created\n", pid);
      break;
 }
 return 0;
}
