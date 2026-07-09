#include <cstdio>
using namespace std;

int euclid(int x,int y)
{
    if(!y) return x;
    else return euclid(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int x,y,t;
    scanf("%d",&t);
    while(t)
    {
        --t;
        scanf("%d%d",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
