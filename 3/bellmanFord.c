//bellman ford
#include<stdio.h>
#include<math.h>
#define INFIN 1000
#define MAX 20
int main()
{
    int n,i,j,u,v,p;
    int adj[MAX][MAX];
    int weight[MAX][MAX];
    int dist[MAX];
    int newdist[MAX];

    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
            weight[i][j]=INFIN;
        dist[i]=INFIN;
    }
    dist[1]=0;
    printf("Enter no of nodes:\n");
    scanf("%d",&n);
    printf("Enter no of weights:\n");
    scanf("%d",&u);
    printf("Enter i j and weight\n");
    for(v=0;v<u;v++)
    {
        scanf("%d %d",&i,&j);
        scanf("%d",&weight[i][j]);
    }
    printf("\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            newdist[j]=dist[j];
        }
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            printf("i=%d j=%d dist[i]=%d dist[j]=%d weight[j][i]=%d ",i,j, dist[i],dist[j],weight[j][i]);
            if(dist[i]<dist[j]+weight[j][i])
            {
                newdist[i]=dist[i];
            }
            else
            {
                newdist[i]=dist[j]+weight[j][i];
            }
            printf("dist[%d] is %d\n",i,newdist[i]);
        }
        for(j=1;j<=n;j++)
        {
            dist[j]=newdist[j];
            //printf("Distance to %d is %d\n",j,dist[j]);
        }
        
    }
        
    
    for(i=1;i<=n;i++)
    {
        printf("Distance to %d is %d\n",i,dist[i]);
    }
    return 0;
}