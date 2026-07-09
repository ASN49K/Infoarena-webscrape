#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int a,b,r;
        f>>a>>b;
        while(b)
        {
            r=b;
            b=b%a;
            a=r;
        }
        g<<a;
        if(i!=n) g<<'\n';
    }
    return 0;
}
