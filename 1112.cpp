
#include<stdio.h>
#define sz 100005
int ar[sz];
int tree[sz*3];

int init(int node,int l,int r)
{
    int left,right,mid;
    if(l==r)
        return tree[node]=ar[l];
    left=node*2;
    right=node*2+1;
    mid=(l+r)/2;
    init(left,l,mid);
    init(right,mid+1,r);
    tree[node]=tree[left]+tree[right];

}
int query(int node,int l,int r,int i,int j)
{
    if(r<i||l>j)
        return 0;
    if(l>=i&&r<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    int a=query(left,l,mid,i,j);
    int b=query(right,mid+1,r,i,j);
    return a+b;
}
int update(int node,int l,int r,int i,int x)
{
    if(i<l||i>r)
        return 0;
    if(l>=i&&r<=i)
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

}
int main()
{
    int i,t,n,cs=1,nmbr,j,k,q,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        init(1,1,n);
        printf("Case %d:\n",cs++);
        for(i=1;i<=q;i++)
        {
            scanf("%d",&nmbr);
            if(nmbr==1)
            {
                scanf("%d",&j);
                printf("%d\n",query(1,1,n,j+1,j+1));
                update(1,1,n,j+1,0);
            }
            else if(nmbr==2)
            {
                scanf("%d%d",&j,&x);
                k=query(1,1,n,j+1,j+1);
                update(1,1,n,j+1,(x+k));
            }
            else if(nmbr==3)
            {
                scanf("%d%d",&j,&k);
                printf("%d\n",query(1,1,n,j+1,k+1));
            }
        }
    }
    return 0;
}
