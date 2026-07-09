#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t, n, x, sol;
    fin >> t;
    while(t--) {
        fin >> n;
        sol=0;
        for(int i=0; i<n; i++) {
            fin >> x;
            sol=(sol^x);
        }
        if(sol==0) {
            fout << "NU\n";
        } else {
            fout << "DA\n";
        }
    }
    return 0;
}
