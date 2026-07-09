#include <iostream>
#include <cstdio>
using namespace std;

int n,x,y;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        while(x!=y)
        {
            if(x>y)
                x-=y;
            else y-=x;
        }
        printf("%d\n",x);
    }
    return 0;
}
