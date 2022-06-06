#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100
char text[MAX],pattern[MAX];
int d,h,p,n,m,t;

int main()
{
    int i,s;
    printf("enter text:\n");
    gets(text);
    printf("enter pattern:\n");
    gets(pattern);
    d=10;
    n=strlen(text);
    m=strlen(pattern);
    h=(int)(float)pow(d,m-1);
    p=0;
    t=0;
    for(i=0;i<m;i++)
    {
        p=d*p+pattern[i];
        t=d*t+text[i];
    }
    for(s=0;s<=n-m;s++)
    {
        if(p==t)
        {
            for(i=0;i<m;i++)
            {
                if(pattern[i]!=text[s+i])
                    break;
            }
            if(i==m)
                printf("pattern occurs with shift %d\n",s);
        }
        if(s<(n-m))
        {
            t=d*(t-text[s]*h)+text[s+m];
        }
    }
}
/*
902314152
31415
*/