#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
long x,y;

int euclid(long a, long b)
{
    if(!b) return a;
    else
    {
        return euclid(b,a%b);
    }
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<"\n";
    }
    f.close();g.close();
    return 0;
}
