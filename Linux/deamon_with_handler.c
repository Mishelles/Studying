/***********************************************************
******Linux course on Stepik. Module 4. Task 4.
-----------------------------------------------------------
******Program to create a simple deamon in Linux and signal
******handler for it.
******Returns deamon's PID
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 3rd of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int signal);

int main(int argc,const char* argv[]) {
  signal(SIGURG, signalHandler);
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

void signalHandler(int signal){
  exit(0);
}
