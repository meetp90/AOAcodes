#include <stdio.h> 

void dijkstra(int a[6][6], int v[], int d[]) {
	int source = 0, selected = 0, c = 0,i,j;	
	while (c < 6) {	
		for ( j = 0; j < 6; j++) {	
			if (v[j] != 1) { 	
				if (a[selected][j] > 0) {
					if ((d[selected] + a[selected][j]) < d[j]) {
						d[j] = d[selected] + a[selected][j];
					}
				}	
			}
			
		}	
		for ( i = 0; i < 6; i++) {
		printf("%d\t", d[i] - 1);
	}
		printf("\n");
	
		int min = 100;
		for ( i = 0; i < 6; i++) {
			if (v[i] != 1) {
				if (d[i] < min) {
					min = d[i];
					selected = i;	
				}
			}
		}
		v[selected] = 1;
		c++;
	}	
}


void main() {
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
	int a[n][n];
    printf("Enter the Adjacency matrix : ");
	int v[6] = {1, 0, 0, 0, 0, 0};
	int d[6] = {1, 100, 100, 100, 100, 100};
	
	dijkstra(a, v, d);
}