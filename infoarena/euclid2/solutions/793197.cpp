#include <iostream>
#include <cstdio>
using namespace std;
int cmmdc (int x , int y)
{
    if(y == 0 )
        return x;
    return cmmdc(y, x%y);
}

int main()
{
    freopen("euclid2.in" ,"r" , stdin);
    freopen("euclid2.out","w" , stdout);
    int t;
    scanf("%d" , &t);
    for(int i = 0 ; i<t; ++i)
    {
        int x ,y ;
        scanf("%d %d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }

    return 0;
}
