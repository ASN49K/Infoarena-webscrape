#include <iostream>
#include<stdio.h>
#define lg 100
using namespace std;

long long a,b,n;

/*long cmmdc(int x,int y)
{
    if(!y) return x;
     else return cmmdc(y,x%y);
}*/


void solve()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>n;

    while(n>0)
    {
        scanf("%l %l",a,b);
        while(b>0)
        {
            int r=a%b;
            a=b;
            b=r;
        }

        printf("%l %l\n",a,b);
        n--;
    }
}


int main()
{
    solve();

    return 0;
}
