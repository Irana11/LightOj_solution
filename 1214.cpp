#include<stdio.h>
#include<string.h>
#define sz 206
char s[sz];

int main()
{
    int i,t,cs,l;
    long long n,d;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%s%lld",&s,&d);
        l=strlen(s);
        n=0;

        for(i=0;i<l;i++)
        {
            if(s[i]=='-')
            {
                continue;
            }
            else
            {
                n=n*10+s[i]-48;
                n%=d;
            }
        }
        if(n==0)
        {
            printf("Case %d: divisible\n",cs);
        }
        else
        {
             printf("Case %d: not divisible\n",cs);
        }
    }
    return 0;

}

