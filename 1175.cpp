#include<stdio.h>
#include<string.h>
#include<queue>
#define sz 210
#define mx 10000000
using namespace std;

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

char ch[sz][sz];
int lev[sz][sz],vis[sz][sz],r,c,moves,ans;
queue<int>q;

void bfs()
{
    int i,j,ux,uy,vx,vy;

    while(!q.empty())
    {
        ux=q.front();
        q.pop();
        uy=q.front();
        q.pop();

        if(ch[ux][uy]=='F'&&vis[ux][uy]==0)
        {
            for(i=0; i<4; i++)
            {
                vx=ux+dx[i];
                vy=uy+dy[i];
                if(vx>=0&&vx<r&&vy>=0&&vy<c&&(ch[vx][vy]=='.'||ch[vx][vy]=='J'))
                {
                    ch[vx][vy]='F';
                    q.push(vx);
                    q.push(vy);
                }
            }
        }
        else
        {
            if(ux==0||ux==r-1||uy==0||uy==c-1)
            {
                if(lev[ux][uy]<ans)
                    ans=lev[ux][uy];
            }
            for(i=0; i<4; i++)
            {
                vx=ux+dx[i];
                vy=uy+dy[i];
                if(vx>=0&&vx<r&&vy>=0&&vy<c&&ch[vx][vy]=='.')
                {
                    ch[vx][vy]='J';
                    vis[vx][vy]=1;
                    lev[vx][vy]=lev[ux][uy]+1;
                    q.push(vx);
                    q.push(vy);
                }
            }
        }
    }
}
int main()
{

    int i,j,t,cs=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                vis[i][j]=0;
            }
        }
        ans=mx;
        for(i=0; i<r; i++)
        {
            scanf("%s",ch[i]);
        }

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(ch[i][j]=='F')
                {
                    q.push(i);
                    q.push(j);
                }
            }
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(ch[i][j]=='J')
                {
                    q.push(i);
                    q.push(j);
                    vis[i][j]=1;
                    lev[i][j]=1;
                }
            }
        }
        bfs();
        if(ans==mx)
            printf("Case %d: IMPOSSIBLE\n",cs++);
        else
            printf("Case %d: %d\n",cs++,ans);

    }
    return 0;
}
