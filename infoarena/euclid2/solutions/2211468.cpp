#include <fstream>
using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int euclid(int a, int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r; //b primeste mereu a%b
    }
    return a; //cand a%b=0 atunci a-ul este cmmdc al celor 2 nr citite
}

int main()
{
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
}
