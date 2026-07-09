#include<fstream>
using namespace std;
long n;
long a,b,i;

long euclid(long a,long b)
{
    long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
}
