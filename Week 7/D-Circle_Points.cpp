// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem D - Circles and Points


#include<cmath>  
#include<cstdio>>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
const int mm=333;  
const double eps=1e-8;  
typedef double diy;  
struct point  
{  
    diy x,y;  
    point(){}  
    point(diy _x,diy _y):x(_x),y(_y){}  
}g[mm];  
bool cmp(point P,point Q)  
{  
    return P.x<Q.x||(P.x==Q.x&&P.y<Q.y);  
}  
diy SqrDis(point P,point Q)  
{  
    return (P.x-Q.x)*(P.x-Q.x)+(P.y-Q.y)*(P.y-Q.y);  
}  
int i,j,n,ans;  
int solve(point P,point Q)  
{  
    point tmp=point((P.x+Q.x)/2,(P.y+Q.y)/2);  
    double angle=atan2(P.y-Q.y,P.x-Q.x)+acos(-1.0)/2;  
    double len=sqrt(1-SqrDis(P,Q)/4);  
    tmp.x+=cos(angle)*len;  
    tmp.y+=sin(angle)*len;  
    int i,ret=0;  
    for(i=0;i<n;++i)  
        if(SqrDis(g[i],tmp)<=1+eps)++ret;  
    return ret;  
}  
int main()  
{  
    while(scanf("%d",&n),n)  
    {  
        for(i=0;i<n;++i)  
            scanf("%lf%lf",&g[i].x,&g[i].y);  
        sort(g,g+n,cmp);  
        ans=n>0;  
        for(i=0;i<n;++i)  
            for(j=i+1;j<n&&(g[j].x-g[i].x)<=2;++j)  
                if(SqrDis(g[i],g[j])<=4)  
                    ans=max(ans,max(solve(g[i],g[j]),solve(g[j],g[i])));  
        printf("%d\n",ans);  
    }  
    return 0;  
} 