//Longest common substring
#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 100
char str1[MAX],str2[MAX];
int mat[MAX][MAX];
void initialize(int n,int m)
{
    int i,j;
    for(i=0;i<=m;i++)
    {
        mat[i][0]=0;
    }
    for(j=0;j<=n;j++)
    {
        mat[0][j]=0;
    }
}
int lcs_length()
{
    int i,j;
    int n,m,a,b;
    m=strlen(str1);
    n=strlen(str2);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=(mat[i][j-1]>mat[i-1][j])?mat[i][j-1]:mat[i-1][j];
            }
        }
    }
    return mat[m][n];
}
void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(mat[i-1][j]>mat[i-1][j-1] || mat[i][j-1]>mat[i-1][j-1])
    {
        if(mat[i-1][j]>=mat[i][j-1])
        {
            print_lcs(i-1,j);
        }
        else
        {
            print_lcs(i,j-1);
        }
    }
    else
    {
        print_lcs(i-1,j-1);
        if(mat[i][j]!=0)
            printf("%c",str1[i-1]);
    }
}
int main()
{
    int n,m;
    int i,j;
    printf("Enter two strings:\n");
    gets(str1);
    gets(str2);
    m=strlen(str1);
    n=strlen(str2);
    initialize(n,m);
    printf("Length of longest common subsequence: %d\n",lcs_length());
    printf("the subsequence is: ");
    print_lcs(m,n);
    printf("\n");

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}