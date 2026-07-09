#include <bits/stdc++.h>
/// Template Dutzu
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    fast
    int t;
    fin>>t;
    for (int k=1;k<=t;k++)
    {
        int n;
        fin>>n;
        int rez=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            fin>>x;
            rez=(rez^x);
        }
        if (rez)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
