#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(long long a, long long b)
{
    long long r;
    if(a>b)
    {
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    else
    {
        while(a!=0)
        {
            r=b%a;
            b=a;
            a=r;
        }
        return b;
    }
}

int main()
{
    long long x,y;
    unsigned int n,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
