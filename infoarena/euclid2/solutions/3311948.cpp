#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid (int x, int y, int r)
{
    if (y==0)
        return x;
    euclid(y, x%y, x%y);
}
int main()
{
    int a, b, r, t;
    f>>t;
    for (int i=1; i<=t; i++)
    {
          f>>a>>b;
    r=a%b;
    g<<euclid (a,b,r);
    g<<endl;
    }

    return 0;
}
