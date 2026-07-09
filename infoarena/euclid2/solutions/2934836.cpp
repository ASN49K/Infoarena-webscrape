#include <bits/stdc++.h>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd (int a, int b)
{
   if (b==0)
   {
       return a;
   }
   return gcd (b,a%b);
}

int main ()
{
    int n, a, b;
    fin>>n;
    for (int i=0; i<n; i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    return 0;
}
