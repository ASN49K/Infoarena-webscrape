
#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
void cetire()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
    }
}
int main()
{
    cetire();
    return 0;
}
