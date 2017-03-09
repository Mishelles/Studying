#include <stdio.h>
#include <stdlib.h>

struct Graveyard{
	int x1;
	int y1;
	int x2;
	int y2;
};

struct Grave{
	int width;
	int heigh;
};

struct Church{
	int x1;
	int x2;
	int y1;
	int y2;
};

int main(int c, char **v){

	int flag=0;

	struct Graveyard graveyard;
	struct Grave grave;
	struct Church church;
	
	
	scanf("%d %d %d %d", &graveyard.x1, &graveyard.y1, &graveyard.x2, &graveyard.y2);
	scanf("%i %i %i %i", &church.x1, &church.y1, &church.x2, &church.y2);
	scanf("%i %i", &grave.width, &grave.heigh);
	
	int iterations=4;
	
	//finding church
	
	int deltaX=church.x1-graveyard.x1;
	int deltaY=graveyard.y2-graveyard.y1;
	
	//go around the church
	
	if ((deltaX<grave.width)||(deltaY<grave.heigh)){
		deltaX=graveyard.x2-graveyard.x1;
		deltaY=graveyard.y2-church.y2;
		if ((deltaX<grave.width)||(deltaY<grave.heigh)){
			deltaX=graveyard.x2-church.x2;
			deltaY=graveyard.y2-graveyard.y1;
			if ((deltaX<grave.width)||(deltaY<grave.heigh)){
				deltaX=graveyard.x2-graveyard.x1;
				deltaY=church.y1-graveyard.y1;
				if ((deltaX>=grave.width)&&(deltaY>=grave.heigh)){
					flag=1;
				}
			}else flag=1;
		}else flag=1;
	}else flag=1;


	if (flag){
		printf("Yes\n");
	}else printf("No\n");
return 0;
}
