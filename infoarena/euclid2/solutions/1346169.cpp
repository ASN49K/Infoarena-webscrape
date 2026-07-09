#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    if (!b)
    return a;
    else euclid (b,a%b);
}
int main()
{
    unsigned int t,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
        t--;
    }
    return 0;
}
