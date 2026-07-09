#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
 ofstream g("euclid2.out");
int cmmdc(int x,int y)
{
    if(!y) return x;
    else return cmmdc(x,x%y);
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
