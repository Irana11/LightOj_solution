#include<stdio.h>
#define sz 1000000
#define i64 long long int

i64 ar[sz];

i64 lower_bound(i64 *ar,i64 n,i64 key)
{
    int lo=0,hi=n-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(ar[mid]>=key)
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    return ans;
}
i64 upper_bound(i64 *ar,i64 n,i64 key)
{
    int lo=0,hi=n-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(ar[mid]<=key)
        {
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    return ans;
}
int main()
{
    i64 i,j,t,cs=1,n,q,min,max,a,b;
    scanf("%lld",&t);
    while(t--)
    {

        scanf("%lld%lld",&n,&q);
		for(i=0;i<n;i++)
			scanf("%lld",&ar[i]);
        printf("Case %lld:\n",cs++);

        for(i=0;i<q;i++)
        {
            scanf("%lld%lld",&a,&b);
            if((a>ar[n-1])||(b<ar[0]))
			{
				printf("0\n");
				continue;
			}

            min=lower_bound(ar,n,a);
            max=upper_bound(ar,n,b);

            printf("%lld\n",max-min+1);
        }
    }
    return 0;
}

