#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t, n;
    fin >> t;
    while(t--){
        fin >> n;
        int xorsum, p;
        fin >> p;
        xorsum = p;
        for(int i = 2; i <= n; ++i){
            fin >> p;
            xorsum ^= p;
        }
        if(xorsum > 0) fout << "DA\n";
        else fout << "NU\n";
    }
    return 0;
}
