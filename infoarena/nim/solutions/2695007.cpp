#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t,n,a,b;
    fin >> t;
    while (t--) {
        fin >> n >> a;
        for (int i = 1;i < n;i++) {
            fin >> b;
            a = (a ^ b);
        }
        if (a == 0)
            fout << "NU";
        else
            fout << "DA";
        fout << '\n';
    }
    return 0;
}
