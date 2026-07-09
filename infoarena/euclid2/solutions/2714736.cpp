#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
//#define f cin
//#define g cout
int t;
int main()
{
    f>>t;
    for(int a,b,c; t; t--)
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
