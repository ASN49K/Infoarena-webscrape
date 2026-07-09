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
        cin>>a>>b;
        while(b>0)
        {
            int r=a%b;
            a=b;
            b=r;
        }

        cout<<a<<'\n';
        n--;
    }
}


int main()
{
    solve();

    return 0;
}
