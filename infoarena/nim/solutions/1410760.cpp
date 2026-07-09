#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t,n,v[100],xorsum;
int main()
{
    f>>t;
    for(int k=1;k<=t;k++)
    {
        f>>n;
        for(int i=1;i<=n;i++){
            f>>v[i];
            xorsum=xorsum^v[i];
        }
        if(xorsum==0)   g<<"NU"<<"\n";
            else    g<<"DA"<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
