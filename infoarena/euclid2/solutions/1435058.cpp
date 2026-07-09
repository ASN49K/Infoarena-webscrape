using namespace std;
#include <fstream>
#include <cmath>

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");


int main ()
{
    int t,a,b,r;
    f>>t;
    while(t--)
    {
        f>>a>>b;
        while (a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<b<<'\n';
    }

}


