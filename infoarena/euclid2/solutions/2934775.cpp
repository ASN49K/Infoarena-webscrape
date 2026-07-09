#include <bits/stdc++.h>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd (int a, int b)
{
    int mini;
    if (a<b)
    {
        mini=a;
    }
    else
        mini=b;
    for (int d=mini; d>=1; d--)
    {
        if (a%d==0 && b%d==0)
        {
            return d;
        }
    }
}

int main ()
{
    int n, a, b;
    fin>>n;
    for (int i=0; i<n; i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
    return 0;
}
