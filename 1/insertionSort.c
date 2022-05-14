#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 50000


void insertionSort(int array[]) {
    int step,i;
    for( step = 1; step < MAX; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
        array[j + 1] = array[j];
            j--;
        }
    array[j + 1] = key;
  }
}

void input_random(int array[]){
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for (i = 0; i < MAX; i++){
		array[i] = rand();
  }
}

void input_best(int array[]){
    int i;
    for ( i = 0; i < MAX; i++)
    {
        array[i] = i;
    }
}

void input_worst(int array[]){
    int i;
    for ( i = 0; i < MAX; i++)
    {
        array[i] = MAX - i;
    }
}

void bestCase(){
    double time_spent = 0.0;
    int data[MAX];
    input_best(data);
    clock_t begin = clock();
    insertionSort(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Best Case : %f", time_spent);
    printf("\n");
}


void averageCase() {
    double time_spent = 0.0;
    int data[MAX];
    input_random(data);
    clock_t begin = clock();
    insertionSort(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Average Case : %f", time_spent);
    printf("\n");
    
}

void worstCase() {
    double time_spent = 0.0;
    int data[MAX];
    input_worst(data);
    clock_t begin = clock();
    insertionSort(data);
    clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Worst Case : %f", time_spent);
    printf("\n");
}


void main(){
    bestCase();
    averageCase();
    worstCase();
}
