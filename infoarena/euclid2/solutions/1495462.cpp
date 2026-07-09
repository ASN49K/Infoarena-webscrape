#include <iostream>
#include <fstream>
using namespace std;

int a,b,t;
int cmmdc(int a, int b)
{
    while((a!=0)&&(b!=0))
    {
        if (a>b) a%=b;
            else b%=a;
    }
    return (a+b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> t;
    for(int i=1; i<=t; i++)
    {
        f >> a >> b;
        g << cmmdc(a,b) << "\n";
    }


    f.close();
    g.close();

    return 0;
}
