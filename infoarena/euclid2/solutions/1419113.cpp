#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b,i,n;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while (b != 0)
    {
        n = b;
        b = a % b;
        a = n;
    }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
