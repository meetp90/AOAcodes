#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 50000


void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int i, j, k;
  int L[n1], M[n2];
  for ( i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for ( j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
          i++;
    } else {
      arr[k] = M[j];
          j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void input_random(int arr[]){
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for (i = 0; i < 50000; i++){
		arr[i] = rand();
  }
}

void input_best(int arr[]){
    int i;
    for ( i = 0; i < MAX; i++)
        arr[i] = i;
}

void input_worst(int arr[]){
    int i;
    for ( i = 0; i < MAX; i++)
        arr[i] = MAX - i;
}

int averageCase() {
    int arr[MAX];
    input_random(arr);
    double time_spent = 0.0;
	clock_t begin = clock();
    mergeSort(arr, 0, MAX - 1);
	clock_t end = clock();
     time_spent += (double)(end - begin);
    printf("Average Case : %f seconds\n", time_spent); 
    return 0;
}

int bestCase() {
    int arr[MAX];
    input_best(arr);
    double time_spent = 0.0;
	clock_t begin = clock();
    mergeSort(arr, 0, MAX - 1);
	clock_t end = clock();
     time_spent += (double)(end - begin);
    printf("Best Case : %f seconds\n", time_spent); 
    return 0;
}

int worstCase(){
    int arr[MAX];
    input_worst(arr);
    double time_spent = 0.0;
	clock_t begin = clock();
    mergeSort(arr, 0, MAX - 1);
	clock_t end = clock();
    time_spent += (double)(end - begin);
    printf("Worst Case : %f seconds\n", time_spent); 
    return 0;
}

int main(){
    averageCase();
    bestCase();
    worstCase();
}