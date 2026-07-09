#include <iostream>
#include <cstdio>

using namespace std;

int euclid(int x,int y)
{
    if(y==0)
        return x;
    else
        return euclid(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        if(x<y)
        {
            int a=x;
            x=y;
            y=a;
        }
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
