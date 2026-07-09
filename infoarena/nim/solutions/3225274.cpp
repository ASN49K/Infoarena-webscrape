#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
    fin.tie(0); fin.sync_with_stdio(false);
    int t; fin>>t;
    while (t--) {
        int n, sol, x;
        fin>>n;
        fin>>sol;
        for (int i=2; i<=n; i++) {
            fin>>x;
            sol=sol^x;
        }
        if (sol==0) fout<<"NU\n";
        else fout<<"DA\n";
    }
    return 0;
}