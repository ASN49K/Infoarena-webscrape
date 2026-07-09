#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, sol;

int main()
{

    fin >> t;

    while(t--){
        fin >> n; sol = 0;

        while(n--){
            int x;
            fin >> x;

            sol ^= x;
        }

        fout << (sol ? "DA\n" : "NU\n");
    }

    return 0;
}
