#include <iostream>
#include <fstream>
using namespace std;
long int t,a,b,i;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;f>>b;i=1;
        while(i)
        {
            i=a%b;
            a=b;
            b=i;
        }
        g<<b<<'\n';
    }
    f.close();g.close();
    return 0;
}
