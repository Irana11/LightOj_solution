#include<stdio.h>
#define sz 110
int vis[sz][sz],c[sz][sz],cost,rvrs_cost;
int t,cs,i,j,k,u,v,a,x,n,y;

void dfs(int i,int j)
{
    if(i<1||j<1||i>n||j>n)
    return;
    if(vis[i][j]==0)
    return;
    vis[i][j]=0;
    vis[j][i]=0;
    for(k=1;k<=n;k++)
    {
         x=vis[j][k];
         if(x==1)
         {
            cost+=c[j][k];
            dfs(j,k);
         }
         else if(x==-1)
         {
            rvrs_cost+=c[k][j];
            dfs(j,k);
         }
    }
}
int main()
{
    scanf("%d",&t);
    cs=1;
    while(t--)
    {
        scanf("%d",&x);
        n=x;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                vis[i][j]=0;
            }
        }
        while(x--)
        {
            scanf("%d%d%d",&u,&v,&a);
            vis[u][v]=1;
            vis[v][u]=-1;
            c[u][v]=a;
        }
        cost=0;
        rvrs_cost=0;
        for(i=1;i<=n;i++)
        {
            if(vis[1][i]==1)
            {
                cost+=c[1][i];
                dfs(1,i);
            }
            else if(vis[1][i]==-1)
            {
                rvrs_cost+=c[i][1];
                dfs(1,i);
            }
        }
        if(cost<rvrs_cost)
        {
            printf("Case %d: %d\n",cs,cost);
        }
        else
        {
             printf("Case %d: %d\n",cs,rvrs_cost);
        }
        cs++;

    }

    return 0;
}
