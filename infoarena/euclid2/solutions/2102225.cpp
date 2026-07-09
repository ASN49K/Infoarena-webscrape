#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int a,b,i,n;
int c(int x, int y)
    {
        if(!y) return x;
        else return c(y,x%y);
    }
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<c(a,b)<<'\n';
    }
    return 0;
}
