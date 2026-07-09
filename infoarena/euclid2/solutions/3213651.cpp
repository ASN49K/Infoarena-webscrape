#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t , a , b , c;
signed main()
{
    fin >> t;
    for(int i = 1 ; i <= t ; ++i)
    {
        fin >> a >> b;
        fout << __gcd(a,b) << '\n';
    }
    return 0;
}
