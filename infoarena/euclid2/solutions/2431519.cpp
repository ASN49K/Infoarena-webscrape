#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,n;
int cmmdc(int a,int b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    f>>n;
    while( f>>x>>y )
        g<<cmmdc(x,y)<<endl;
}
