#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,r;
int main()
{
    f>>t;
    for(;t;t--) /// "de t ori"
    {
        f>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        /// a=cmmdc b=0
        g<<a<<'\n';
    }

    return 0;
}

