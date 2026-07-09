#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void Euclid(int a, int b)
{
    int r = a % b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    fout<<b<<"\n";
}

int main()
{
    int n, a, b;
    fin>>n;
    while(n)
    {
        fin>>a>>b;
        Euclid(a, b);
        n--;
    }
    return 0;
}
