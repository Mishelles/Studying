/***********************************************************
******This is my simple version of Who in Unix/Linux
------------------------------------------------------------
******Created by Mikhail Sergeenkov on 16th of February, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

 int main(int argc, char const *argv[]) {
   int fd=open(UTMP_FILE,O_RDONLY);
   struct utmp current_record;
   ssize_t record_len=sizeof(current_record);
   if (fd==-1){
     perror(UTMP_FILE);
     fprintf(stdout, "Something went wrong\n");
    exit(1);
    }
  while(read(fd, &current_record, record_len)==record_len){
    if (current_record.ut_type==USER_PROCESS)
      fprintf(stdout, "%s\n", current_record.ut_user);
      fprintf(stdout, "%s\n", ctime(current_record.ut_tv.tv_sec) );
  }
   close(fd);
   return 0;
 }
