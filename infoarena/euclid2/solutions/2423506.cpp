#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,a,b;
    f>>t;
    while(t--)
    {
        f>>a>>b;
        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
