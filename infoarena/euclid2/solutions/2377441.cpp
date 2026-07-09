#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b;
    f>>a;
    f>>b;
    int cmmdc=1;
    int i;
    for (i=2;i<=min(a,b);i++)
    {
        if (a%i==0&&b%i==0) cmmdc=i;
    }
    g<<cmmdc;
    g.close();
    f.close();

    //varianta de 30 de puncte
    return 0;
}
