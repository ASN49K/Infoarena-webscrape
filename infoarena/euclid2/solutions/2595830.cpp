#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int cmmdc(int a, int b);

int main()
{

    fin >> t;
    while(t--){
        fin >> a >> b;
        if(a < b) swap(a, b);

        fout << cmmdc(a, b) << "\n";
    }

    return 0;
}

int cmmdc(int a, int b){
    if(!(a % b)) return b;

    return cmmdc(b, a % b);
}
