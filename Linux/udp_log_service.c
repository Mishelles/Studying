/***********************************************************
******Linux course on Stepik. Module 5. Task 2.
-------------------------------------------------------------
******Sumple UDP logging service
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

int main(int argc, char const *argv[]) {

  if (argc!=2)
    return -1;

  int sock=socket(AF_INET, SOCK_DGRAM, 0);

  unsigned int port=atoi(argv[1]);
  inet_aton("127.0.0.1", &local.sin_addr);
  local.sin_family=AF_INET;
  local.sin_port=htons(port);

  int result=bind(sock, (struct sockaddr*)&local, sizeof(local));

  char buf[BUFSIZ];
  while(read(sock, buf, BUFSIZ)){
    if (strncmp(buf, "OFF\n", 4)==0) break;
    fprintf(stdout, "%s", buf);
    memset(buf, 0, BUFSIZ);
  }

  return 0;
}
