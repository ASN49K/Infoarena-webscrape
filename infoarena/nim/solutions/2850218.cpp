#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

void solve()
{
    int n,sumxor=0;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        f>>x;
        sumxor^=x;
    }
    if(sumxor!=0) g<<"DA"<<'\n';
    else g<<"NU"<<'\n';
}

int main()
{
    int teste;
    f>>teste;
    while(teste--)
        solve();
}
