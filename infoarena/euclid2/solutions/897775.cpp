#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long di(long,long);


int main()
{

    long long i,a,b,n;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        fout<<di(a,b)<<'\n';
    }
    return 0;
}

int di(int a,int b)
{
    long long r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
return a;
}
