#include<stdio.h>
#include<math.h>
#define sz 1000010
#define sz1 80000
int i,j,k,rt,cnt,num;
int ar[sz],pr[sz1];

void sieve()
{
    num=sz-5;
    long long i,j;
    k=0;
    pr[k]=2;
    k++;
    ar[0]=ar[1]=1;
    for(i=3;i<=num;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=num;j+=(i*2))
            {
                ar[j]=1;
            }
            pr[k]=i;
            k++;
        }
    }
}
int main()
{
    int t,cs,m=1;
    long long num;
    sieve();
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%lld",&num);
        rt=sqrt(num);
        i=0;
        m=1;
        while(pr[i]<=rt&&num!=1)
        {
            cnt=0;
            while(i<k&&num!=1&&num%pr[i]==0)
            {
                cnt++;
                num=num/pr[i];
                rt=sqrt(num);
            }
            m=m*(cnt+1);
            i++;
        }
        if(num>1)
        {
            m=m*(2);
        }
        m-=1;
        printf("Case %d: %d\n",cs,m);
    }
    return 0;
}
