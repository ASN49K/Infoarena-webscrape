#include <fstream>

using namespace std;

int r,a,b,n,i;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void rezolvare()
{
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    g<<b<<"\n";
}

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a>>b;
    rezolvare();
    }
}
