#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    if (b==0)
    return a;
    else euclid (b,a%b);
}
int main()
{
    unsigned int t,i,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
    }
    return 0;
}
