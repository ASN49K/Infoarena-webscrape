#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int x;
void solve()
{
    int suma=0;
    int n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        suma=(suma^x);
    }
    if(suma==0)
        fout<<"NU\n";
    else
        fout<<"DA\n";
}
int main()
{
    int t;
    fin>>t;
    while(t--)
        solve();
    return 0;
}
