#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in"); ofstream fout("euclid2.out");

int n;
int a, b;

void euclid() {
    if(b > a)
        swap(a, b);
    while(b > 0) {
        a -= b;
        if(b > a)
            swap(a, b);
    }
    fout << a << "\n";
}

void solve() {
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a >> b, euclid();
}

void fclose() {
    fin.close(), fout.close();
}

int main()
{
    solve();
    fclose();
    return 0;
}
