#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long euclid(long long a,long long b)
{
    if(b==0) return a;
    return euclid(b,a%b);
}

int t,i,c,d;

int main()
{
    fin>>t;
    for(i=1;i<=t;++i)
    {
        fin>>c>>d;
        fout<<euclid(c,d)<<'\n';
    }
    return 0;
}
