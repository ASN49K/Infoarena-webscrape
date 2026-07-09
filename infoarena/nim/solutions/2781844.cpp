#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t;
void solve_test()
{
    f>>n;
    int XOR = 0;
    for(int i=1;i<=n;i++)
    {
        int x;
        f>>x;
        XOR^=x;
    }
    if(XOR)
    {
        g<<"DA"<<'\n';
        return;
    }
    g<<"NU"<<'\n';
}
int main()
{
    f>>t;
    for(int test=1;test<=t;test++)
    {
        solve_test();
    }
    return 0;
}
