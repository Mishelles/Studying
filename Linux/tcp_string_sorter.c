/***********************************************************
******Linux course on Stepik. Module 5. Task 3.
-------------------------------------------------------------
******Sumple TCP derver which sorts symbols of strings
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 8th of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct sockaddr_in local;

int cmp(const void * x1, const void * x2);

int main(int argc, char const *argv[]) {

    if (argc!=2)
      return -1;

    int ss=socket(AF_INET, SOCK_STREAM, 0); //server socket
    int cs; //client socket

    unsigned int port=atoi(argv[1]);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_family=AF_INET;
    local.sin_port=htons(port);

    int result=bind(ss, (struct sockaddr*)&local, sizeof(local));
    listen(ss, 5);

    cs=accept(ss, NULL, NULL);

    char buf[BUFSIZ];

    while(read(cs, buf, BUFSIZ)){
      if (strncmp(buf, "OFF", 3)==0) break;
      qsort(buf, strlen(buf), sizeof(char), cmp);
      write(cs, buf, strlen(buf));
      memset(buf, 0, BUFSIZ);
    }

    close(cs);
  return 0;
}

int cmp(const void * x1, const void * x2){
  return ( *(char*)x2 - *(char*)x1 );
}
