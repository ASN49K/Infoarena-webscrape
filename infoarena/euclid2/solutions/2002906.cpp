#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out.cpp");
int nr,a,b,r,i;
int main()
{
    f>>nr;
    for(i=1; i<=nr; i++)
    {
        f>>a>>b;
        while(b)
            r=a%b,a=b,b=r;
        g<<a<<'\n';
    }
    return 0;
}
