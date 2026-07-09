#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,s,x;
    fin >> t;
    while(t--){
        fin >> n;
        s = 0;
        while(n--){
            fin >> x;
            s ^= x;
        }
        fout << (s ? "DA" : "NU") << "\n";
    }
    return 0;
}
