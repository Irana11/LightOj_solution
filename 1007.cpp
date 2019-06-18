#include<stdio.h>
#include<math.h>
#define sz 5000010

int i,j,n1,n2,t,cs=1;

bool ar[sz];
unsigned long long phi[sz];
int cnt_pr=0;

void sieve()
{
    long long i,j,rt,num=sz-5;
    rt=sqrt(num);
    phi[1]=0;
    for(i=2;i<=num;i++)
    {
        phi[i]=i;
        if(i%2==0)
        {
            phi[i]/=2;
        }
    }

    ar[0]=ar[1]=1;

    for(i=3;i<=num;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=num;j+=(2*i))
            {
                ar[j]=1;
            }
            for(j=i;j<=num;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
        ar[i+1]=1;
    }

    for(i=2;i<=num;i++)
    {
        phi[i]=(phi[i]*phi[i])+phi[i-1];
    }
}

int main()
{
    sieve();
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n1,&n2);
        printf("Case %d: %llu\n",cs++,phi[n2]-phi[n1-1]);
    }
    return 0;
}
