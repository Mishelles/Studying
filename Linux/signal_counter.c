/***********************************************************
******Linux course on Stepik. Module 4. Task 3.
-------------------------------------------------------------
******Program counts signals SIGUSR1 and SIGUSR2 and after
******handling SIGTERM puts returns two numbers
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 3rd of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <signal.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int counter1=0;
int counter2=0;

void signalHandler(int signal);

int main(int argc, char const *argv[]) {
  /*Redefine signals*/
  signal(SIGUSR1, signalHandler);
  signal(SIGUSR2, signalHandler);
  signal(SIGTERM, signalHandler);
  while (1){

  }
  return 0;
}

void signalHandler(int signal){
  if (signal==SIGUSR1){
    ++counter1;
  }else if (signal==SIGUSR2){
    ++counter2;
  }else if (signal==SIGTERM){
    printf("%d %d\n", counter1, counter2);
    exit(0);
  }
}
