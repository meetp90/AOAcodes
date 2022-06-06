//sum of subset
#include <stdio.h>
#define MAX 100


void output(int x[],int n){
    int i;
    for (int i = 0; i < n; i++) {
        printf("%d\t",x[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      x[i] = 0;
    }
}

void sumOfSub(int array[],int s,int k,int r,int n,int m,int x[]){
    x[k] = 1;
    if(s + array[k] == m) 
        output(x,n);
    else if(s + array[k] + array[k+1] <= m) 
        sumOfSub(array,s+array[k],k+1,r-array[k],n,m,x);
    if ((s + r - array[k] >= m) && (s + array[k+1] <= m)){
        x[k] = 0;
        sumOfSub(array,s,k+1,r - array[k],n,m,x);
    }
}

void main(){
    int data[MAX],i,n,m,x[MAX];
    int r = 0;
    printf("Enter the length of the array");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    printf("Enter the elements :\n");
    for ( i = 0; i < n; i++) {
        scanf("%d",&data[i]);
        r += data[i];
    }
    printf("\nEnter the sum required : ");
    scanf("%d",&m);
    sumOfSub(data,0,0,r,n,m,x);
}
