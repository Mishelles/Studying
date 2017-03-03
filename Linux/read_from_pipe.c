/***********************************************************
******Linux course on Stepik. Module 4. Task 1.
-------------------------------------------------------------
******Program reads another program's output and counts zeros
******in it using popen()
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 3rd of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 200

int main (int argc, char* const argv[]){
	if (argc<1){
		printf("Passing some arguments\n");
		exit(1);
	}
	char command[LEN];
	int counter=0;
	sprintf(command, "%s %s", argv[1], argv[2]);
	FILE *pipe_descr=popen(command, "r");
	char sym;
	sym=fgetc(pipe_descr);
	if (sym=='0') ++counter;
	while(sym!=EOF){
		sym=fgetc(pipe_descr);
		if (sym=='0'){
			++counter;
		}
	}
	printf("%d\n", counter);
	pclose(pipe_descr);
	return 0;
}
