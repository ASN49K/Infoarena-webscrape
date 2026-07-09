#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int i,a,b,d,T,j;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
        {f>>a;
    f>>b;
    if(a>b)
        {for(j=1;j<=b;j++)
        if(b%j==0 && a%j==0)
        d=j;
    g<<d<<endl;}
    else
        {for(j=1;j<=a;j++)
        if(b%j==0 && a%j==0)
        d=j;
        g<<d<<endl;;}
        }

        f.close();
        g.close();
        return 0;

}
