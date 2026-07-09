#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,t;
int euclid(int x,int y)
{
    if(!y)
        return x;
    else
        return euclid (y,x%y);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t)
    {
        {
            scanf("%d %d", &a, &b);
            if(a<b)
                swap(a,b);
            printf("%d\n",euclid(a,b));
        }
        --t;
    }
    return 0;
}
