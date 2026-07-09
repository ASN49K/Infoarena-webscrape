#include <iostream>
#include <fstream>
using namespace std;


int cmmdc(int x, int y)
{
    while(x*y!=0)
    {
        if(x>y) x%=y;
           else y%=x;
    }
    return (x+y);
}


int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n,a,b;
    f >> n;
    for(int i=1; i<=n; i++)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }


    f.close();
    g.close();
    return 0;
}
