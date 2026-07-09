#include <bits/stdtr1c++.h>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

long long int cmmdc(long long int a,long long int b)
{
    long long int r;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}

int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
