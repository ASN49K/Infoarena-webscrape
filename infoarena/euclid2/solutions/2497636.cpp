#include <bits/stdc++.h>

using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

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
