#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
long long a,b;

int main()
{

    fin >> T;

    for(;T;T--)
    {
        fin >> a >> b;
        fout << __gcd(a,b) << endl;
    }

    return 0;

}
