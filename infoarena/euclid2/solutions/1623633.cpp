#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n,a,b;
    cin>>n;

    while(cin>>a>>b)
    {
        int r;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    return 0;
}
