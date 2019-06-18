
#include<stdio.h>

int ar[101],pr[30],p[30],cnt[101],i,j,k,n,m,t,cs,mx;

void sieve()
{
    ar[0]=ar[1]=1;
    k=0;
    pr[k]=2;
    k++;
    for(i=3;i<=100;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=100;j+=2*i)
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
    sieve();
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        mx=0;
        for(i=0;i<100;i++)
        {
            cnt[i]=0;
        }
        scanf("%d",&n);
        for(i=2;i<=n;i++)
        {
            m=i;
            j=0;
            while(j<k&&m!=1)
            {
                 while(m%pr[j]==0&&m!=1&&j<k)
                {
                    cnt[pr[j]]++;
                    m=m/pr[j];
                    if(j>mx)
                    {
                        mx=j;
                    }
                }
                j++;
            }


        }
        printf("Case %d: %d =",cs,n);
        for(i=0;i<=mx;i++)
        {
            if(i==mx)
            {
                printf(" %d (%d)\n",pr[i],cnt[pr[i]]);
                continue;
            }
            printf(" %d (%d) *",pr[i],cnt[pr[i]]);
        }
    }
    return 0;

}
