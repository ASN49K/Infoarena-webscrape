#include <bits/stdc++.h>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    while(b)
    {
        int r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int t;
    in>>t;

    while(t--)
    {
        int a, b;
        in>>a>>b;

        if(a < b) swap(a,b);

        out<<euclid(a,b)<<'\n';
    }
}
