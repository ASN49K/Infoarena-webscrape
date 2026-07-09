#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a[100001],b[100001];
int main()
{
    fin >> t;
    for(int i=1;i<=t;i++) {
        fin >> a[i] >> b[i];
    }
    for(int i=1;i<=t;i++) {
        fout << __gcd(a[i],b[i]) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
