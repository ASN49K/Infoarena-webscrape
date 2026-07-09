#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
 ofstream g("euclid2.out");
int cmmdc(int x,int y)
{
    if(  x == y) return x;
    else if( x > y) return cmmdc(x-y,y);
    else return cmmdc(x,y-x);
}

int main()
{
   int n ;
    f >> n;
    for(int i=1, a, b;i <= n; i++)
    {
        f >> a >> b;

         g << cmmdc(a,b) << '\n';
    }
}
