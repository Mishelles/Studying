/***********************************************************
******Linux course on Stepik. Module 4. Task 5.
-------------------------------------------------------------
******Program sums up the first 100 numbers from two regions
******and puts them in new shared memory region.
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 3rd of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define REGION_SIZE 10000
#define N 100

int main(int argc, char const *argv[]) {
  if (argc<2){
    printf("Passing arguments\n");
    return 0;
    }

    int one=atoi(argv[1]);
    int two=atoi(argv[2]);
    int i=0;
    int three=one+two;

    int shmid1=shmget(one, REGION_SIZE, 0600);
    int* shared1=(int*)shmat(shmid1,NULL,0);

    int shmid2=shmget(two, REGION_SIZE, 0600);
    int* shared2=(int*)shmat(shmid2,NULL,0);

    int shmid3=shmget(three, REGION_SIZE, IPC_CREAT | 0666);
    int* shared3=(int*)shmat(shmid3,NULL,SHM_RND);

    for(i=1;i<N;++i){
      shared3[i]=shared1[i]+shared2[i];
    }
    printf("%i\n",three);

    shmdt(shared1);
    shmdt(shared2);
    shmdt(shared3);

    return 0;
}
