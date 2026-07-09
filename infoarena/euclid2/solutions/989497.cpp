#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i,t,a,b,r,aux;
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        if(b<a)
        {
            aux=a;
            a=b;
            b=aux;
        }
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
        g.flush();
    }
    return 0;
}
