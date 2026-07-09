#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y)
{
    int c;
    while (y)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}

void read()
{
    int t;
    int a,b;
    int i;
    in>>t;
    for(i=1;i<=t;++i)
    {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
}

int main()
{
    read();
    return 0;
}
