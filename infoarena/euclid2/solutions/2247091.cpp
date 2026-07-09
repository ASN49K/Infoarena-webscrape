#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    if(a==0)
        return b;
    return euclid(b%a,a);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    f>>t;
    while (t!=0)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
        t--;
    }
    return 0;
}
