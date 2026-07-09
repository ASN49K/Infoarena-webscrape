#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("nim.in");
    ofstream g("nim.out");

    int t; f >> t;
    for(int cas=1; cas<=t; cas++) {
        int n; f >> n;
        int rez = 0;
        for(int i=1; i<=n; i++) {
            int x; f >> x;
            rez = rez ^ x;
        }
        if(rez) g << "DA\n";
        else g << "NU\n";
    }
    return 0;
}
