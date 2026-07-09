#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n , a , b;

int CMMDC(int a , int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> n;
    while(n--)
    {
        fin >> a >> b;
        fout << CMMDC(a , b) << "\n";
    }
    return 0;
}
