#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long GCD(long long a,long long b)
{
    if(!b)
        return a;
    else
        return GCD(b,a%b);
}

int main()
{
    long long T,a,b;
    fin>>T;

    for(long long i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<GCD(a,b)<<"\n";
    }

    return 0;
}
