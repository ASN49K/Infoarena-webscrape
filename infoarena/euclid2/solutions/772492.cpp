#include <fstream>
#include <iostream>

using namespace std;

long lnko(long a,long b)
{
    long r=a%b;
    while (r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    long a,b;
    f>>n;
    for (int i=0;i<n;i++)
        {
        f>>a>>b;
        g<<lnko(a,b)<<endl;
        }
    f.close();
    g.close();
}
