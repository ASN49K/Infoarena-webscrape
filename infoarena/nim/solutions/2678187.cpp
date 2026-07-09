#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main() {

    int t;

    f >> t;

    while(t){
        --t;

        int n, s = 0;

        f >> n;

        for(int i = 1; i <= n; ++i){
            int x;

            f >> x;

            s ^= x;
        }

        if(s) g << "DA\n";
        else g << "NU\n";
    }

    return 0;
}
