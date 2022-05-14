#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 50000

int partition (int a[], int start, int end){  
	int j;
    int pivot = a[end];
    int i = (start - 1);  
  
    for ( j = start; j <= end - 1; j++)  
    {  
        if (a[j] < pivot)  
        {  
            i++;   
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
void quick(int a[], int start, int end){  
    if (start < end)  
    {  
        int p = partition(a, start, end);   
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
} 

void input_random(int a[]){
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for (i = 0; i < 50000; i++)
		a[i] = rand();
}

void input_best(int a[]){
    int i;
    for ( i = 0; i < MAX; i++)
        a[i] = i;
}

void input_worst(int a[]){
    int i;
    for ( i = 0; i < MAX; i++)
        a[i] = MAX - i;
}
     
int averageCase(){
    int a[MAX];  
    input_random(a);
	double time_spent = 0.0;  
    clock_t begin = clock();
    quick(a, 0, MAX - 1);  
    clock_t end = clock();
   time_spent += (double)(end - begin);
    printf("Average Case: %f\n", time_spent);
    return 0;  
} 

int bestCase(){
    int a[MAX];  
    input_best(a);
	double time_spent = 0.0;  
    clock_t begin = clock();
    quick(a, 0, MAX - 1);  
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Best Case: %f\n", time_spent);
    return 0;  
} 

int worstCase(){
    int a[MAX];  
    input_worst(a);
	double time_spent = 0.0;  
    clock_t begin = clock();
    quick(a, 0, MAX - 1);  
    clock_t end = clock();
   time_spent += (double)(end - begin);
    printf("worst Case: %f\n", time_spent);
    return 0;  
} 

void main(){
    worstCase();
    bestCase();
    averageCase();
}