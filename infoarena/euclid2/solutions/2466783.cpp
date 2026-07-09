#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, A, B;

    fin >> T;
    while(T--)
    {
        fin >> A >> B;
        fout << __gcd(A, B) << '\n';
    }



return 0;
}

