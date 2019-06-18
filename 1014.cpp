#include<stdio.h>
#include<math.h>
#define sz 50000
int ar1[sz];

int main()
{
    int t,cs=1,p,i,q,n,l,rt,j,k=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&p,&l);


        printf("Case %d:",cs++);
        q=p-l;
        rt=sqrt(q);

        if(q<=l)
        {
            printf(" impossible\n");
            continue;
        }

        for(i=1,j=0;i<=rt;i++)
        {
            if(q%i==0)
            {
                ar1[j]=i;
                j++;
            }
        }

        for(i=j-1,k=j;i>=0;i--)
        {
            if((ar1[i]*ar1[i])!=q)
            {
                ar1[k]=q/ar1[i];
                k++;
            }
        }

        for(i=0;i<k;i++)
        {
            n=p%ar1[i];
            if(n==l)
            {
                printf(" %d",ar1[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
