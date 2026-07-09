#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    int r = a % b;
    if(!r)
    {
        return b;
    }
    else
    {
        return euclid(b,r);
    }
}

int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=0;i<t;++i)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
