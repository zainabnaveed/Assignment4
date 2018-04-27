#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

int arr[1000];
int total=0;
int arrind[10]= {0,100,200,300,400,500,600,700,800,900};
void* SumThreadFunc(void* arg);

int main()
{
   for(int i=0; i<1000; i++)
   {
   	arr[i]= i+1;
   }
 
   printf("Creating Threads");
   pthread_t threads[10];
   for(int j=0; j<10; j++)
   {
	pthread_create(&threads[j], NULL, SumThreadFunc, (void*) &arrind[j] ); 
   }

   for(int k=0; k<10; k++)
   {
	pthread_join(threads[k], NULL); 
   }

   //printf("Total= %d",total);
   return 0;

}

void* SumThreadFunc(void* arg)
{
   int* temp= (int*) arg;
   int sum=0;
   for(int i=*temp; i<*temp+100; i++)
   {
	sum= sum + arr[i];
	total= total + sum;
   }
   printf("Total= %d",total);
}
