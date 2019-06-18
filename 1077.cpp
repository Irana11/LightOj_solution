#include<stdio.h>

long long gcd(long long a,long long b)
{
    long long tmp;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

int main()
{


    int t,cs;
    long long x1,x2,y1,y2,x,y,tmp,g;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        if(x1>x2)
        {
            tmp=x2;
            x2=x1;
            x1=tmp;
        }
        if(y1>y2)
        {
            tmp=y2;
            y2=y1;
            y1=tmp;
        }
        x=x2-x1;
        y=y2-y1;

        g=gcd(x,y);
        g=g+1;
        printf("Case %d: %lld\n",cs,g);

    }
    return 0;
}
