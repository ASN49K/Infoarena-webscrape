#include <bits/stdc++.h> 
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.in");
long long a, b, n;
int main()
{
    ios::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
    fin >> a >> b;
    while(b)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    if(a == 1)
        cout << '0';
    else
        fout << a;
    }
    return 0;
}