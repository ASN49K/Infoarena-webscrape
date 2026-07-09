#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    while (b!=0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    int a, b, t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
      fin>>a>>b;
      fout<<gcd(a,b)<<'\n';
    }
    return 0;
}
