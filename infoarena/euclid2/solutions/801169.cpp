#include<cstdio>
using namespace std;
int a,b,T;
int euclid(int a,int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    for(;T;T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d \n",euclid(a,b));
    }
    return 0;
}
