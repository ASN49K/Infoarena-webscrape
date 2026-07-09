#include <fstream>

using namespace std;
int t,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int x,int y)
{
    int r;
    do
    {
        r=x%y;
        x=y;
        y=r;
    } while (r!=0);
    return x;
}
void citire ( )
{
    f>>a;
    f>>b;
    g<<cmmdc(a,b)<<'\n';
    t--;
    if (t>0) citire( );
}
int main()
{  f>>t;
    citire();
    return 0;
}
