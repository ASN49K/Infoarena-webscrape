#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
    }
    return 0;
}
