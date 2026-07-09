#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a ,b ,i;
int gcd(long int a,long int b)
{
    int r;
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int t;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
    return 0;
}
