#include <bits/stdc++.h>
#define NMAX 110

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int Euclid(int a, int b) {
    if(b == 0) return a;
    else return Euclid(b, a % b);
}

int main()
{
    fin >> n;
    while(n--) {
        fin >> a >> b;
        fout << Euclid(a, b) << '\n';
    }
    return 0;
}
