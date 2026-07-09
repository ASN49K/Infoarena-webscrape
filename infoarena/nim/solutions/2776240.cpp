#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

void usain_bolt()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
}

int main()
{
    usain_bolt();

    int tt;

    fin >> tt;
    for(; tt; --tt) {
        int n, xorr = 0;

        fin >> n;
        for(int i = 1; i <= n; ++i) {
            int x;

            fin >> x;
            xorr ^= x;
        }
        if(xorr) {
            fout << "DA" << "\n";
        }
        else {
            fout << "NU" << "\n";
        }
    }
    return 0;
}
