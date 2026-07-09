#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,n,k,i;
    f>>n;
    int cmmdc;
    for (k=1;k<=n;k++)
    {
        cmmdc=1;
        f>>a;
        f>>b;
        for (i=2;i<=min(a,b);i++)
        {
            if (a%i==0&&b%i==0) cmmdc=i;
        }
        g<<cmmdc<<"\n";
    }
    g.close();
    f.close();
    //varianta de 30 de puncte
    return 0;
}
