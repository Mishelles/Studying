/***********************************************************
******Linux course on Stepik. Module 4. Task 2.
-------------------------------------------------------------
******Program reads data from two named pipes (FIFO)
******using select()
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 3rd of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 256

int main(int argc, char const *argv[]) {
  int fd1 = open("in1", O_RDONLY, O_NONBLOCK);
  int fd2 = open("in2", O_RDONLY, O_NONBLOCK);
  int sum=0;
  if(fd1 < 0){
      printf("In1 does not exist\n");
  }
  if(fd2 < 0){
      printf("In2 does not exist\n");
  }
  while((fd1>0)||(fd2>0)){
    fd_set fds;
    int maxfd;
    int res;
    char buf[BUF_SIZE];
    int num1, num2;
    FD_ZERO(&fds); /* Clear FD set for select*/
    FD_SET(fd1, &fds);
    FD_SET(fd2, &fds);

    maxfd = fd1 > fd2 ? fd1 : fd2;

    select(maxfd + 1, &fds, NULL, NULL, NULL);

    if (FD_ISSET(fd1, &fds)){
      /*Reading from fd1*/
      res = read(fd1, buf, sizeof(buf));
      if (res > 0){
          num1=atoi(buf);
        }
      }
      if (FD_ISSET(fd2, &fds)){
        /*Reading from f21*/
        res = read(fd2, buf, sizeof(buf));
        if (res > 0){
          num2=atoi(buf);
        }
      }
      sum=sum+num1+num2;
  }
  printf("%d\n", sum);
  return 0;
}
