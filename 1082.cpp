
#include<stdio.h>
#define sz 100005
int ar[sz];
int tree[sz*3];

int init(int node,int l,int r)
{
    if(l==r)
        return tree[node]=ar[l];
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    init(left,l,mid);
    init(right,mid+1,r);
    if(tree[left]<tree[right])
        tree[node]=tree[left];
    else
        tree[node]=tree[right];

}
int query(int node,int l,int r,int i,int j)
{
    if(r<i||l>j)
        return 1000000;
    if(l>=i&&r<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    int a=query(left,l,mid,i,j);
    int b=query(right,mid+1,r,i,j);
    if(a<b)
        return a;
    else
        return b;
}
/*int update(int node,int l,int r,int i,int x)
{
    if(i<l||i>r)
        return 0;
    if(l<=i&&r>=i)
    {
        tree[node]=x;
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    update(left,l,mid,i,x);
    update(right,mid+1,r,i,x);
    tree[node]=tree[left]+tree[right];

}*/
int main()
{
    int i,t,n,cs=1,q,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);

        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        init(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,1,n,x,y));

        }
    }
    return 0;
}
