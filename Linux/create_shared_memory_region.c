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
#define REGION_SIZE 1000
#define N 100

int main(int argc, char const *argv[]) {
  if (argc<2){
    printf("Passing arguments\n");
    return 0;
    }

    key_t one=(key_t)atoi(argv[1]);
    key_t two=(key_t)atoi(argv[2]);
    int i=0;
    key_t three=19900604;

    int shmid1=shmget(one, REGION_SIZE, 0660);
    int* shared1=(int*)shmat(shmid1,(void*)0,SHM_RDONLY);

    int shmid2=shmget(two, REGION_SIZE, 0660 );
    int* shared2=(int*)shmat(shmid2,(void*)0,SHM_RDONLY);

    int shmid3=shmget(three, REGION_SIZE, IPC_CREAT | 0644);
    int* shared3=(int*)shmat(shmid3,(void*)0,0);

    for(i=0;i<N;++i){
      shared3[i]=shared1[i]+shared2[i];
    }
    printf("%i\n",(int)three);

    shmdt(shared1);
    shmdt(shared2);
    shmdt(shared3);

    return 0;
}
