#include<stdio.h>
#include<queue>
#define sz 10100
using namespace std;
int lev[sz],vis[sz];
int ar[sz],pr[sz];

void sieve()
{

    long long int i,j;
    int num=sz-5;
    pr[0]=2;
    int k=1;
    ar[0]=ar[1]=1;

    for(i=3;i<num;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<num;j+=(i*2))
            {
                ar[j]=1;
            }
            pr[k]=i;
            k++;
        }
        ar[i+1]=1;
    }
  // printf("%d\n",k);
}
void bfs(int s,int d)
{
    int u,v,i;
    queue<int>q;
    q.push(s);
    lev[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;pr[i]<u/2+1;i++)
        {
            if(u%pr[i]==0)
            {
                v=u+pr[i];
                if(!vis[v]&&v<=d)
                {
                    lev[v]=lev[u]+1;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int a,b,t,cs=1,i,j;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        for(i=1;i<=b;i++)
            vis[i]=0;
        bfs(a,b);
        if(vis[b]==1)
            printf("Case %d: %d\n",cs++,lev[b]);
        else
            printf("Case %d: -1\n",cs++);
    }
    return 0;
}
