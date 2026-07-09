#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
int cmmdc(int x,int y)
{
    if(y==0)
        return x;
    return cmmdc(y,x%y);

}
int main()
{
    int x,y,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
