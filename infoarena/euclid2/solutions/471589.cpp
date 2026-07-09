#include <iostream>
#include <stdio.h>
#define fin "euclid2.in"
#define fout "euclid2.out"
using namespace std;


int main()
{
    freopen(fin,"r",stdin);
    freopen(fout,"w",stdout);
    int a,b,c,n;
    cin>>n;
    while(n)
    {
        cin>>a>>b;
        if(a<b)
        {
            c=a;a=b;b=c;
        }
        while(a)
        {
            b=b%a;
            c=a;a=b;b=c;
        }
        cout<<b<<"\n";
        n--;
    }
    return 0;
}
