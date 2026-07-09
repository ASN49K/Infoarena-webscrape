#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    if(b == 0)
        return a;
    else return cmmdc(b, a % b);
}

pair<int,int>pereche;
int n;

int main() {
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> pereche.first >> pereche.second;
        fout << cmmdc(pereche.first, pereche.second) << '\n';
    }
}

