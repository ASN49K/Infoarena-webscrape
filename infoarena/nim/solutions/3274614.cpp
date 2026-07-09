#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t, n;
    f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>n;
        int val=0;
        for(int j=1; j<=n; j++)
        {
            int x;
            f>>x;
            val=val^x;
        }
        if(val==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }
    return 0;
}
