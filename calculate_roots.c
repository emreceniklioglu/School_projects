#include<stdio.h>
#include<math.h>

void get_input( int size, int numbers[]){
	
	int m = 0,sayi;
	while(m != 1){
		
		scanf("%d",&sayi);
		if(sayi != 0){
			numbers[m] = sayi;
			m++;
		}	
	}
	for (m;m<3;m++){
		scanf("%d",&sayi);
		numbers[m] = sayi;
	}
		
}

void print_equation(int size, int numbers[]){
	if(numbers[0] <0)
		printf("-%d",numbers[0]);
	else
		printf("%d",numbers[0]);
	printf("x^2");
	if (numbers[1] != 0){
		if(numbers[1] <0)
		printf("%dx",numbers[1]);
		else
		printf("+%dx",numbers[1]);
	}
	if(numbers[2] != 0){
		if(numbers[2] <0)
		printf("%d",numbers[2]);
		else
		printf("+%d",numbers[2]);
	}
	
	printf("\n");
}

float discriminant( int size, int numbers[]){
	return numbers[1]*numbers[1]-4*numbers[0]*numbers[2];
	
}

void print_roots( int size, int numbers[]){
	int a,b;
	int disc = discriminant(size,numbers);
	if (disc<0)
		printf("-");
	else if (disc==0)
	{
	
		a = (numbers[1]*-1)/2*numbers[0];
		printf("%d",a);
	}
	else{
		a = ((numbers[1]*-1) + sqrt(disc))/2*numbers[0];
		b = ((numbers[1]*-1) - sqrt(disc))/2*numbers[0];
		printf("%d %d",a,b);
	}	
}
int main(){
	int size = 3;
	int numbers[size];
	get_input(size, numbers);
	print_equation(size, numbers);
	printf("%.1f\n", discriminant(size, numbers));
	print_roots(size, numbers);	
return 0;
}
