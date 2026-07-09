#include <iostream>
#include <fstream>

using namespace std;


ifstream f("nim.in");
ofstream g("nim.out");

int t,n,a,xors;

int main()
{
    f>>t;
    while(t)
    {
        t--;
        f>>n;
        xors=0;
        for(int i=1;i<=n;i++)
        {
            f>>a;
            xors=xors^a;
        }
        if(xors!=0)
            g<<"DA"<<endl;
        else
            g<<"NU"<<endl;
    }
    return 0;
}
