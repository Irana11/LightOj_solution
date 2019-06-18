#include<stdio.h>
#include<algorithm>
#define sz 2010
using namespace std;

int ar[sz];

int upper_bound(int *ar,int n,int key)
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
        else if(ar[mid]>key)
            hi=mid-1;
    }
    return ans;
}
int main()
{
    int t,n,cs=1,i,j,indx,cnt,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+n);

        sum=0;
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                sum=ar[i]+ar[j];
                indx=upper_bound(ar,n,sum-1);
                if(indx!=-1)
                    cnt+=(indx-j);
            }
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
