#include<stdio.h>
#define sz 101


int main()
{
    int i,j,t,cs=1,n,m,x,y,k,tmp;
    int ar[sz];
    char ch;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<m;i++)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='M'||ch=='S'||ch=='D')
            {
                scanf("%d",&x);
                if(ch=='S')
                {
                    for(j=0;j<n;j++)
                        ar[j]+=x;
                }
                else if(ch=='M')
                {
                     for(j=0;j<n;j++)
                         ar[j]*=x;
                }
                else
                {
                     for(j=0;j<n;j++)
                        ar[j]/=x;
                }
            }
            else if(ch=='P')
            {
                scanf("%d%d",&x,&y);

                tmp=ar[x];
                ar[x]=ar[y];
                ar[y]=tmp;
            }
            else
            {
                x=n/2;
                for(j=0,k=n-1;j<x;j++,k--)
                {
                    tmp=ar[k];
                    ar[k]=ar[j];
                    ar[j]=tmp;
                }
            }
        }
        printf("Case %d:\n",cs++);
        for(i=0;i<n-1;i++)
            printf("%d ",ar[i]);
        printf("%d\n",ar[i]);
    }

    return 0;
}
