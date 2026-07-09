#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
/**
12 36

*/
int cmmdc(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    int n,a,b;
    while(n--)
    {
        fin >> a >> b;
        fout << cmmdc(a,b);
    }
    return 0;
}
