#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 200

int main (int c, char* const atgv[]){
	
	char* str=(char*)malloc(LEN*sizeof(char));
	char* name=(char*)malloc(LEN*sizeof(char));
	char** word=(char**)malloc(LEN*sizeof(char*));
	for(int i=0; i<LEN; ++i){
		word[i]=(char*)malloc(LEN*sizeof(char));
	}
	
	int j=0;
	int k=0;
	
	fgets(str, LEN, stdin);
	
	//Parsing string
	
	for(int i=0; i<LEN; ++i){
		if (!(isspace(str[i]))){
			word[k][j]=str[i];
			++j;
		}
		else{
			j=0;
			++k;
		}
	}
	
	/*for(int i=0; i<LEN; ++i){
		for (int j=0; j<LEN; ++j){
			printf("%c", word[i][j]);
		}
		printf("\n");
	}*/
	
	for(int i=0; i<LEN; ++i){
		for(int j=0; j<LEN; ++j)
	}
	
	return 0;
}
