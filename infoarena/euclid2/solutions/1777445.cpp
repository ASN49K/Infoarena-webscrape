#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int main()
{
    fin>>t;
    for(t;t>0;t--){
        int a,b;
        fin >>a>>b;
        fout <<__gcd(a,b)<<endl;

    }

    return 0;
}
