#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,t,d=1,m,i;
    f>>t;
    while(t!=0)
    {
        f>>a;
        f>>b;
        if(a>b) m=b;
        else m=a;
        for(i=1;i<=m;i++)
        {
            if(a%i==0 && b%i==0) d=i;
        }
        g<<d<<"\n";
        t--;
    }
    f.close();
    g.close();
    return 0;
}
