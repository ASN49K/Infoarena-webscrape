#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,r,i;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;f>>b;r=1;
        while(r!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    f.close();g.close();
    return 0;
}
