#include<stdio.h>
#include<string.h>
#define MAX 100
char pattern[MAX],text[MAX];
int table[MAX];
int m,n;
void computePrefix()
{
    int k,q;
    table[0]=0;
    k=0;
    for(q=1;q<m;q++)
    {
        while(k>0 && pattern[k]!=pattern[q])
            k=table[k];
        if(pattern[k]==pattern[q])
            k=k+1;
        table[q]=k;
    }
}
int main()
{
    int i,q;
    printf("enter text:\n");
    gets(text);
    printf("enter pattern:\n");
    gets(pattern);
    n=strlen(text);
    m=strlen(pattern);
    computePrefix();
    q=0;
    for(i=0;i<n;i++)
    {
        while(q>0 && pattern[q]!=text[i])
            q=table[q];
        if(text[i]==pattern[q])
        {
            q++;
        }
        if(q==m)
        {
            printf("pattern found at shift of %d\n",i-m+1);
            q=table[q];
        }
    }
}