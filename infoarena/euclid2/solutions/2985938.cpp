#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,n;
    fin>>n;
    for(int i = 0;i<n;++i){
        fin>>a>>b;
        fout<<__gcd(a,b)<<"\n";
    }
    return 0;
}