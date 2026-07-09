#include <iostream>
#include <fstream>
using namespace std;
ifstream f("agar.in");
ofstream g("agar.out");
int t,i,a,b,r;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        g<<a<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
