#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,a,b,r;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
     scanf("%d %d",&a,&b);
     while(b!=0)
     {
        r=a%b;
        a=b;
        b=r;
     }
     printf("%d\n",a);
    }
    return 0;
}
