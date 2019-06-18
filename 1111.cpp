#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int>vec[10005];

int lev[1005],vis[1005],ar[105],cnt[1005],result,i,j,node,t,cs=1,u,v,k,n,m;

int bfs(int s)
{
    queue<int>q;
    int i,l,j,u,v;
    q.push(s);
    cnt[s]++;
   // vis[s]=1;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(i=0;i<l;i++)
        {
            v=vec[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                cnt[v]++;
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&k,&n,&m);
        for(i=1;i<=k;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
            vis[j]=0;
        }

        for(i=1;i<=k;i++)
        {
            bfs(ar[i]);
            for(j=1;j<=n;j++)
                vis[j]=0;
        }

        result=0;
        printf("Case %d:",cs++);
        for(i=1;i<=n;i++)
        {
            if(cnt[i]==k)
                result++;
        }
        printf(" %d\n",result);
        for(i=0;i<=m;i++)
        {
            vec[i].clear();
        }

    }
    return 0;

}


