#include <stdio.h>

int main(){
	
	int i,j,row,col,ykordinat,xkordinat,grupsayisi = 0,ilksatir;
	scanf("%d %d",&row,&col);
	int array[row][col];
	int Copyarray[row][col];
	//int yýldýzadet[row][col];
	for (i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
		  array[i][j] = 0;
		}
		
	}
	
	for (i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
		  Copyarray[i][j] = 0;
		}
		
	}
	
	scanf("%d %d",&xkordinat,&ykordinat);
	array[xkordinat][ykordinat] = 1;
	Copyarray[xkordinat][ykordinat] = 1;
	grupsayisi = 1;
	ilksatir = xkordinat;
	
	while(xkordinat != -1){
		
	scanf("%d",&xkordinat);
	if (xkordinat == -1){
		break;
	}
	scanf("%d",&ykordinat);
	array[xkordinat][ykordinat] = 1;
	
	Copyarray[xkordinat][ykordinat] = 1;
	
	
	if (xkordinat == ilksatir)
	{
		if(array[xkordinat][ykordinat-1] == 1){
			continue;
		}
		else
		grupsayisi++;
	}
	
	else{
		
		if(array[xkordinat-1][ykordinat] == 1)
		{ 									// satýrlarýn üst komþusunun 1 olup olmadýðýný sorgula              
			continue;
		}
		else
		{// üst komþunun olmamasý hali
			
			if(xkordinat >= 1 && ykordinat == 0)  //sol kenarda olmasý
			{ 
				if(array[xkordinat-1][ykordinat+1] == 1){ //sað üst çapraz kontrol
					continue;
				}
				else
				grupsayisi++;		
			}
			
			else if(xkordinat>=1 && ykordinat == col-1) //sað kenarda olmasý
			{
				if(array[xkordinat-1][ykordinat-1] != 1){ //sol üst çapraz kontrol
					grupsayisi++;
				}		
			} 
			
			else // ortada bir yerde olmasý
			{
				
				
				if(array[xkordinat-1][ykordinat+1] == 1 && array[xkordinat-1][ykordinat-1] == 1 && grupsayisi >1){ // iki çapraz 1 olmasý
					grupsayisi--;
				}
				
				else if(array[xkordinat-1][ykordinat+1] == 1 && array[xkordinat-1][ykordinat-1] != 1 && grupsayisi >1 && array[xkordinat][ykordinat-1] == 1){ 
					grupsayisi--;
				}
				
				else if(array[xkordinat][ykordinat-1] == 1){
					continue;
				}
				
				else if(array[xkordinat-1][ykordinat-1] == 1){
					continue;
				}
				
				else if(array[xkordinat-1][ykordinat+1] == 1){
					continue;
				}
				
				else{
					grupsayisi++;
				}
			}
			
		}	
	}		
}


	for (i = 0;i<row;i++)  // kendisi + komþu hücre sayisi 
	{
		for(j = 0;j<col;j++)
		{
			if(array[i][j] == 1)
			{
				if (i>0){
					Copyarray[i][j] += array[i-1][j];
				}
				if(i<row-1){
					Copyarray[i][j] += array[i+1][j];
				}
				if(j>0){
					Copyarray[i][j] += array[i][j-1];
				}
				if(j<col-1){
					Copyarray[i][j] += array[i][j+1];
				}
				
				if(i>0 && j<col-1){
					Copyarray[i][j] += array[i-1][j+1];
				}
				
				if(i<row-1 && j<col-1){
					Copyarray[i][j] += array[i+1][j+1];
				}
				
				if(i>0 && j>0){
					Copyarray[i][j] += array[i-1][j-1];
				}
				
				if(i<row-1 && j>0){
					Copyarray[i][j] += array[i+1][j-1];
				}
			}
			
		}
		
		
	}
	

	for (i = 0;i<row;i++) // komsu hücrelerdekinden küçükse sýfýrla
	{
		for(j = 0;j<col;j++)
		{
			if(Copyarray[i][j] > 1)
			{
				
				if (i>0){
					if(Copyarray[i][j] <= Copyarray[i-1][j]){
						Copyarray[i][j] = 0;
					}	
				}
				if(i<row-1){
					if(Copyarray[i][j] <= Copyarray[i+1][j]){
						Copyarray[i][j] = 0;
					}
				}
				if(j>0){
					if(Copyarray[i][j] <= Copyarray[i][j-1]){
						Copyarray[i][j] = 0;
					}
				}
				if(j<col-1){
					if(Copyarray[i][j] <= Copyarray[i][j+1]){
						Copyarray[i][j] = 0;
					}
				}
				
				if(i>0 && j<col-1){
					if(Copyarray[i][j] <= Copyarray[i-1][j+1]){
						Copyarray[i][j] = 0;
					}
				}
				
				if(i<row-1 && j<col-1){
					if(Copyarray[i][j] <= Copyarray[i+1][j+1]){
						Copyarray[i][j] = 0;
					}
				}
				
				if(i>0 && j>0){
					if(Copyarray[i][j] <= Copyarray[i-1][j-1]){
						Copyarray[i][j] = 0;
					}
					
				}
				
				if(i<row-1 && j>0){
					if(Copyarray[i][j] <= Copyarray[i+1][j-1]){
						Copyarray[i][j] = 0;
					}
				}
				
			}
			
		}
		
		
	}
	
	
	void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
	int sonuc[grupsayisi]; // sonuc arrayi henüz belli deðil
	
    for (i = 0; i < grupsayisi - 1; i++){
    	 for (j = 0; j < grupsayisi - i - 1; j++){
    	 	if (sonuc[j] > sonuc[j + 1])
                swap(&sonuc[j], &sonuc[j + 1]);	
		 }
            
	}
	
	
	/*for(i = 0;i<grupsayisi;i++){
		printf("%d \n",sonuc[i]);
	}*/
	for (i = 0;i<row;i++) // Ekrana basma.
	{
		for(j = 0;j<col;j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
		
	printf("%d",grupsayisi);
	

	return 0;
}
