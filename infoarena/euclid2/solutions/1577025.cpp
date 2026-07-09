#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,T,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    while(T>0)
    {
        f>>a>>b;
        while(b!=0)
        {
        r=a%b;
        a=b;
        b=r;
        }
        g<<a<<'\n';
     T--;
    }
    f.close();
    g.close();
    return 0;
}
