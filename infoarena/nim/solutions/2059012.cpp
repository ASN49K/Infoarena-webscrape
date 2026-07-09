#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int n,t,a;
    f>>t;
    for (int i=1;i<=t;++i)
    {
        f>>n;
        int sumxor=0;
        for (int i=1;i<=n;++i)
        {
            f>>a;
            sumxor=sumxor^a;
        }
        if (sumxor==0) g<<"NU"<<'\n';
        else g<<"DA"<<'\n';
    }
    return 0;
}
