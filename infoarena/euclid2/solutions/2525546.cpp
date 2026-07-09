#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    long long  a, b, rest, t, i;
    fin>>t;
    for(i=1;i<=t;i++)
    {fin >> a >> b;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    fout<<a;}
    return 0;
}
