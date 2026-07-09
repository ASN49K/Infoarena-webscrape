#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i,t,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
    return 0;
}
