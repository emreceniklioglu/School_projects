#include <stdio.h>
#include <pthread.h>

int sum;
void *runner(void *param);	
int main(int argc,char*argv[]) {
   
	pthread_t tid;
	pthread_attr_t attr;
	
	if(argc !=2){
		return -1;
	}
	if(atoi(argv[1] < 0 )){
		return -1;
	}
   
   	pthread_attr_init(&attr);
   	pthread_create(&tid,&attr,runner,argv[1]);
   	pthread_join(tid,NULL);
	printf("sum: %d\n",&sum);  
   
}
void *runner(void *param){
	sum = factorial((int)param);
	pthread_exit(0);
}

int factorial(int n){
	if(n == 1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
	
}


