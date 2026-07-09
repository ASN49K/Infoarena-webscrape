#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    int d=a,i=b,r;
    do {
        r=d%i;
        d=i;
        i=r;
        }
        while (r);
    return d;

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b;
    f>>n;
    for (;n;n--)
        {
            f>>a>>b;
            g<<cmmdc(a,b)<<"\n";
        }
    g.close();
    return 0;
}
