// DJIKTRA
#include <stdio.h>
#define MAX 100
#define OG 999

int cost[MAX][MAX];
int list[MAX];
int distance[MAX], parent[MAX];
void initialize(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		list[i] = 0;
		distance[i] = OG;
		parent[i] = OG;
	}
	distance[0] = 0;
}
void relax(int u, int v)
{
	distance[v] = (distance[v] > distance[u] + cost[u][v]) ? distance[u] + cost[u][v] : distance[v];
	// printf("%d\t",distance[v]);
}
int extractMin(int n)
{
	int i;
 	int min = MAX;
	int mini = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && list[i] != 1)
		{
			mini = i;
			min = distance[i];
		}
	}
	if (mini != -1)
		list[mini] = 1;
	return mini;
}
void djiktra(int n)
{
	int i, j, k, u, v;
	u = extractMin(n);
	list[0] = 1;
	while (u != -1)
	{
		for (i = 0; i < n; i++)
		{
			if (cost[u][i] != OG || cost[i][u] != OG)
			{
				relax(u, i);
			}
		}
		u = extractMin(n);
	}
}
int main()
{
	int i, j, k, n, e, u, v, a, b, w, l;
	printf("Number of nodes:\n");
	scanf("%d", &n);
	printf("Number of edges:\n");
	scanf("%d", &e);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			cost[i][j] = OG;
		}
	}
	printf("Enter the startnode endnode weight:\n");
	for (i = 0; i < e; i++){
		scanf("%d %d %d", &a, &b, &w);
		cost[a][b] = w;
		cost[b][a] = w;
	}
	initialize(n);
	djiktra(n);
	printf("The final distants are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", distance[i]);
	}
}