
#include<stdio.h>
#include<math.h>
#define sz 1000005
double a[sz];

int main()
{
    int i,j,t,x,n,b,d;
    double sb,s;
    a[1]=0;
    for(i=2;i<=sz;i++)
    {
        a[i]=a[i-1]+log10(i);
    }
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {

        scanf("%d%d",&n,&b);
        s=a[n];
        sb=s/log10(b);
        d=floor(sb)+1;
        printf("Case %d: %d\n",x,d);
    }
    return 0;
}
