#include <bits/stdc++.h>

using namespace std;

unsigned euclid(unsigned u, unsigned v)
{
    while (v!= 0)
    {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main()
{
    unsigned cont,u,v;
    ifstream f("euclid2.in");
    f>>cont;
    ofstream g("euclid2.out");
    while(cont--)
    {
        f>>u>>v;
        g<<euclid(u,v)<<'\n';
    }
    return 0;
}
