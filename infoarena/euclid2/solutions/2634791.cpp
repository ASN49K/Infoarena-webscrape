#include <bits/stdc++.h>

using namespace std;
int Euclid_rec(int a, int b)
{
    if(b==0)
        return a;
    else
        return Euclid_rec(b, a%b);
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
        g<<Euclid_rec(a,b)<<'\n';
    }
    f.close();
    return 0;
}
