#include <stdio.h>
#include <fstream>
using namespace std;
int t, a, b;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 int cmmdc(int x,int y);
int main()
{
    f>>t;
    for (int i=0;i<t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<< '\n';
    }

    return 0;
}
int cmmdc(int x, int y)
{
    if(!y)
        return x;
    return cmmdc(y,x%y);
}
