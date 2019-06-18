#include<stdio.h>
#define i64 long long int

i64 a,b,c,d,e,f,n;
i64 dp[1000000];

i64 fn(i64 n)
{
    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;
    if(n==3) return d;
    if(n==4) return e;
    if(n==5) return f;
    if(dp[n]!=-1)
    return dp[n];
    else
    {
        dp[n]=fn(n-1)%10000007+fn(n-2)%10000007+fn(n-3)%10000007+fn(n-4)%10000007+fn(n-5)%10000007+fn(n-6)%10000007;
        return dp[n];
    }

}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&n);
        for(int i=0;i<=n;i++)
        dp[i]=-1;

        printf("Case %d: %lld\n",cs++,fn(n)%10000007);
    }
    return 0;
}
