#include<stdio.h>
int main(){
	int array[8][8],i,j,posx,posy;
	for (i = 0;i<8;i++){
		for (j = 0;j<8;j++){
			array[i][j] = 0;
		}
	}
	scanf("%d,%d",&posx,&posy);
	array[posx][posy] = "*";
	if (posy+2 < 8 && posx -1>0){
		array[posx-1][posy+2] = 1;
	}
	if (posy+1 < 8 && posx -2>0){
		array[posx-2][posy+1] = 1;
	}
	if (posy+2 < 8 && posx+1 < 8){
		array[posx+1][posy+2] = 1;
	}
	if (posy+1 < 8 && posx+2<8){
		array[posx+2][posy+1] = 1;
	}
	if (posy-2 > 0 && posx-1 > 0){
		array[posx-1][posy-2] = 1;
	}
	if (posy-1 > 0 && posx-2>0){
		array[posx-2][posy-1] = 1;
	}
	if (posy-2 >0 && posx+1<8){
		array[posx+1][posy-2] = 1;
	}
	if (posy-1 >0 && posx+2<8){
		array[posx+2][posy-1] = 1;
	}
	for (i = 0;i<8;i++){
		for (j = 0;j<8;j++){
			if (i == posx && j == posy){
				printf("%s ",array[i][j]);
			}
			else
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}

