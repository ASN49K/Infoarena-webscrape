#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int Euclid (int a, int b)
{
    if (a==0) return b;
    if (a>b) Euclid(a%b,b);
    else  Euclid(b%a,a);
}
int main()
{
    int nrteste, nr1, nr2;
    f>>nrteste;
    for (int i=0;i<nrteste;i++)
    {
        f>>nr1>>nr2;
        g<<Euclid (nr1,nr2)<<"\n";
    }
    return 0;
}
