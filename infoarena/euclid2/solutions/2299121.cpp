#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,r,i;
int main()
{
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (i=1;i<=t;i++)
        {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
        }
    f.close();g.close();
    return 0;
}
