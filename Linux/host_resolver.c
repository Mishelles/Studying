/***********************************************************
******Linux course on Stepik. Module 5. Task 1.
-------------------------------------------------------------
******Program prints IP addresses associated with given hostname
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 7th of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  if (argc!=2)
    return -1;

  struct hostent *host;
  host=gethostbyname(argv[1]);

  if (NULL==host)
    printf("Error!\n" );

  int i=0;
  while(host->h_addr_list[i]!=NULL){
    struct in_addr *a=(struct in_addr*)host->h_addr_list[i];
    printf("%s\n", inet_ntoa(*a));
    ++i;
  }

  return 0;
}
