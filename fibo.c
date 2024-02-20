#include<stdio.h>
int main(){
	int ilk=1;
	int iki=1;
	int a;
	int c;
	printf("bir deger gir:");
	scanf("%d",&c);
	printf("%d\n%d\n",ilk,iki);
	// 1 1 2 3 5
	int i;
	for (i=0;i<(c-2);i++){
		
		a = ilk +iki;
		ilk = iki;
		iki = a;
		printf("%d\n",iki);
	}
	return 0;


}
