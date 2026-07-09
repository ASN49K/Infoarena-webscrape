#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

void citire();
long long int euclid(long long int, long long int);

int main()
{
    citire();
    return 0;
}

void citire()
{
    int i;
    long long int a, b;
    fin>>t;
    for(i=1;i<=t;++i)
    {
        fin>>a>>b;
        fout<<euclid(a, b)<<'\n';
    }
}

long long int euclid(long long int a, long long int b)
{
    if(!b) return a;
    return euclid(b, a%b);
}
