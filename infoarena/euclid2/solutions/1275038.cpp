#include <iostream>
#include <fstream>

using namespace std;

int main()
{   int a,b,r,t,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }


    f.close();
    g.close();

    return 0;
}
