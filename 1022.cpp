#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main()
{
    int i,T;
    double r,sqa,ra,s;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf",&r);
        sqa=(2*r)*(2*r);
        ra=pi*r*r;
        s=sqa-ra;
        printf("Case %d: %0.2lf\n",i,s);

    }
    return 0;
}
