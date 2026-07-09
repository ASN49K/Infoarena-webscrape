#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int t;
int main()
{
    fin>>t;
    int a,b;
    for(t;t>0;t--){

        fin >>a>>b;
        fout <<gcd(a,b)<<endl;

    }

    return 0;
}
