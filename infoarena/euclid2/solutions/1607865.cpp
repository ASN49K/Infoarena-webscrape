#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,a,b,r;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }while(r);
        g<<a<<'\n';
    }
    f.close();
    g.close();
}
