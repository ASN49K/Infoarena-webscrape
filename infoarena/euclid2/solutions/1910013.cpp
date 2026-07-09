#include <iostream>
#include <fstream>
using namespace std;

int T,a,b;

int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    ifstream fin ("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    return 0;
}
