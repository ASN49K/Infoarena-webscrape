#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,i;
int cmmdc(int a,int b)
{
{
    if (!b) return a;
    return gcd(b, a % b);
}

}
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
