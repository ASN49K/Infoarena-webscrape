#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long T,i,a,b,c;

int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<'\n';
    }
    return 0;
}
