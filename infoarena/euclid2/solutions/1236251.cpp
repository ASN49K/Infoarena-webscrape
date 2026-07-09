#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,na,nb;

int Euclid(int a,int b)
{
    if(a%b == 0)
        return b;
    else
        return Euclid(b,a%b);
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>na>>nb;
        g<<Euclid(na,nb)<<"\n";
    }
    return 0;
}
