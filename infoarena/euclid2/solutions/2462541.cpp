#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,a,b;
int euclid(int a, int b)
{
    int rest = 0;
    while(b)
    {
        rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}
int main()
{
    for(in>>n;n;n--)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
    return 0;
}
