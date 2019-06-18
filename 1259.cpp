#include<stdio.h>
#include<math.h>

#define sz1 10000010
#define sz2 664585

int i,j,k,rt;
int pr[sz2];
bool ar[sz1];

void sieve()
{
    k=0;
    for(i=2;i<sz1;i++)
    {
        ar[i]=1;
    }
    for(i=2;i<sz1;i++)
    {
        if(ar[i]==1)
        {
            for(j=2;i*j<sz1;j++)
            {
                ar[i*j]=0;
            }
            pr[k]=i;
            k++;
        }
    }

}

int main()
{
    int t,cs,n,cnt,sub,flg;
    sieve();
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        cnt=0;
        scanf("%d",&n);

        for(i=0;pr[i]<=(n/2);i++)
        {
            sub=n-pr[i];
            if(ar[sub]==1)
            {
                cnt++;
            }
        }
        printf("Case %d: %d\n",cs,cnt);
    }
    return 0;

}

