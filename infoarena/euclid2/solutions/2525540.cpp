#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int a, b, rest;
    fin >> a >> b;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    fout<<a;
    return 0;
}
