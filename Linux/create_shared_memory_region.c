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

  key_t key1=atoi(argv[1]);
  key_t key2=atoi(argv[2]);
  key_t new_key;

  int id1=shmget(key1, REGION_SIZE, 0600);
  int id2=shmget(key2, REGION_SIZE, 0600);
  int id3=shmget(new_key, REGION_SIZE, 0666);

  int* attach_one=(int*)shmat(id1,0,SHM_RND);
  int* attach_two=(int*)shmat(id2,0,SHM_RND);
  int* attach_new=(int*)shmat(id3,0,SHM_RND);

  int i=0;
  for (i=0; i<N; ++i){
    *attach_new=*attach_two+*attach_two;
    ++attach_one;
    ++attach_two;
    ++attach_new;
  }


  printf("%d\n", (int) new_key);

  return 0;
}
