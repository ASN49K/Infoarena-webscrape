#include <iostream>
#include <stdio.h>
#define fin "euclid2.in"
#define fout "euclid2.out"

using namespace std;

int main()
{
    freopen(fin,"r",stdin);
    freopen(fout,"w",stdout);

    long a,b,r,n;
    cin>>n;
    while(n)
    {
        cin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<"\n";
        n--;
    }

    return 0;
}
