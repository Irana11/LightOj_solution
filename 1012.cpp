#include<stdio.h>

int i,j,k,h,w,t,cs,cnt;
int vis[30][30];
char ch[30][30];
char c;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=h||j>=w)
    return;
    if(ch[i][j]=='#'||vis[i][j]==1)
    return;

    vis[i][j]=1;
    cnt++;
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int main()
{
    cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&w,&h);
        getchar();
        for(i=0;i<h;i++)
        {
            gets(ch[i]);
            for(j=0;j<w;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(ch[i][j]=='@')
                {
                    cnt=0;
                    dfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n",cs,cnt);
        cs++;
    }
    return 0;
}
