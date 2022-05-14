#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 50000

void selection(int array[]){
        int i,j,min,temp;
        for ( i = 0; i < MAX - 1; i++)
        {
            min = array[i];
            for( j = i + 1; j < MAX; j++)
                if (array[j] < min)
                    min = array[j];
            temp = array[i];
            array[i] = min;
            min = temp;
        }
        
}

void input_best(int array[]){
    int i;
    for ( i = 0; i < MAX; i++)
        array[i] = i;
}

void input_average(int array[]){
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for ( i = 0; i < MAX; i++)
        array[i] = rand();
}


void bestCase(){
    double time_spent = 0.0;
    int data[MAX];
    input_best(data);
    clock_t begin = clock();
    selection(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Best Case : %f",time_spent);
    printf("\n");
}

void input_worst(int array[]){
    int i;
    for ( i = 0; i < MAX; i++)
        array[i] = MAX - i;
}

void averageCase(){
    double time_spent = 0.0;
    int data[MAX];
    input_average(data);
    clock_t begin = clock();
    selection(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Average Case : %f",time_spent);
    printf("\n");
}

void worstCase(){
    double time_spent = 0.0;
    int data[MAX];
    input_worst(data);
    clock_t begin = clock();
    selection(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("worst Case : %f",time_spent);
    printf("\n");
}


void main(){
    bestCase();
    averageCase();
    worstCase();    
}