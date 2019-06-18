#include<stdio.h>
#define sz 1010
int ar[sz],res[sz],n,k;

int check(int x)
{
    int i,j=0;
    int day=k;
    int sum=ar[0];

    for(i=1;i<n+1;i++)
    {
        if(sum+ar[i]<=x)
            sum+=ar[i];
        else
        {
            day--;
            sum=0;
            i--;
        }
    }
    if(day<0)
        return 0;
    else
        return 1;
}
int main()
{
    int i,j,sum,hi,lo,mid,t,cs=1,mx,chk,ans,path,day;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&k);
        path=mx=0;

        for(i=0;i<n+1;i++)
        {
            scanf("%d",&ar[i]);
            path+=ar[i];
            if(ar[i]>mx)
                mx=ar[i];
        }
        lo=mx;
        hi=path;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            chk=check(mid);
            if(chk)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %d\n",cs++,ans);
        sum=0;
        day=k+1;
        n++;
        for(i=0;i<n;i++)
        {
            if(sum+ar[i]<=ans)
                sum+=ar[i];
            else
            {
                printf("%d\n",sum);
                day--;
                sum=ar[i];
            }
            if(n-i==day)
            {
                printf("%d\n",sum);
                for(j=i+1;j<n;j++)
                {
                    printf("%d\n",ar[j]);
                }
                break;
            }

        }
       // printf("%d\n",sum);

    }

    return 0;
}
