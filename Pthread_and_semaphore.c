#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define maxrow 100
#define maxcol 100

sem_t semaphore;
int row,col,thread_num;
int matrix[maxrow][maxcol];
int array[maxcol];

void *routine(void *args) {
    sem_wait(&semaphore);
    int coll = *(int*)args,i;
    int sum = 0;
    for(i = 0;i<row;i++){
        sum += matrix[i][coll];
    }
    array[coll] = sum;
    sem_post(&semaphore);
    free(args);
    
}
void *print(void *args) {
   
   int n = *(int*)args,i,j;
   
   int temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
     for (i=0; i < n; i++){
        printf("%d ", array[i]);
    }
   
   
    pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    int number,i,j;
    scanf("%d %d",&row,&col); 
    thread_num = col;
    pthread_t th[thread_num];
    for(i = 0;i<row;i++){
		for(j = 0;j<col;j++){
			scanf("%d",&number);
			matrix[i][j] = number;
		}
	}

    sem_init(&semaphore,0,1);
    
    for (i = 0; i < thread_num; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a)) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < thread_num; i++) {
        if (pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }
    
    pthread_t lastthread;
    pthread_create(&lastthread, NULL, &print, (void*)&col);
    pthread_join(lastthread, NULL);
   
    sem_destroy(&semaphore);
    return 0;
}
