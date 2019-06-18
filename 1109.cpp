#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct ss
{
    int cnt,nmbr;
}ar[1005];

bool cmp(ss aa,ss bb)
{
    if(aa.cnt==bb.cnt)
    return aa.nmbr>bb.nmbr;
    return aa.cnt<bb.cnt;
}

int main()
{
    int n,i,j,cnt,x,t,rt;
    ar[0].nmbr=1;
    ar[0].cnt=1;
    for(i=2;i<=1000;i++)
    {
        rt=sqrt(i);
        cnt=0;
        for(j=1;j<=rt;j++)
        {
            if(i%j==0)
            {
                if(j*j==i)
                {
                    cnt++;
                }
                else
                {
                    cnt+=2;
                }

            }
        }

        ar[i-1].cnt=cnt;
        ar[i-1].nmbr=i;
    }
    sort(ar,ar+1000,cmp);
    for(i=0;i<1000;i++)
    {
        printf("%d %d %d\n",i,ar[i].nmbr,ar[i].cnt);
    }

   /* scanf("%d",&t);
    x=1;
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",x,ar[n-1].nmbr);
        x++;

    }*/
    return 0;

}
