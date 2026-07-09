#include <bits/stdc++.h>

using namespace std;
int Euclid_iter(int a, int b)
{
    while(b!=0)
    {
        int t;
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, a, b;
    f>>n;
    for(int i = 0; i < n; i++)
    {
        f>>a>>b;
        g<<Euclid_iter(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
    return 0;
}
