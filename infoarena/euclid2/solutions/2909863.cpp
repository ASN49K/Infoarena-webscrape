#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out"); 
long long x,y;
int t;

long long gcd(long long a,long long b)
{
    while (a>0 && b>0)
    {
        if (a>b) a=a%b;
        else b=b%a;
    }
    if (a>0) return a;
    else return b;
}

int main()
{
    fin >> t ;
    while (t--)
    {
        fin >> x >> y ;
        fout<< gcd(x,y)<<"\n";
    }
    return 0;
}