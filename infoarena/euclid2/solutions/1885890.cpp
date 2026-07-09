#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


long long c(long long a,long long b)
{
    long long r=a%b;
    while(r!=0)
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
    for(int i=1;i<=t;i++)
    {
        long long x,y;
        fin>>x>>y;
        fout<<c(x,y)<<endl;
    }
    return 0;
}
