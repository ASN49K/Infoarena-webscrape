#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int a,t,n,ns=0;
void Read()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>n;
        ns=0;
        for(int j=1;j<=n;j++) {f>>a;ns=(ns^a);}
       if(ns) g<<"DA\n"; else g<<"NU\n";
    }
}


int main()
{
    Read();
    return 0;
}
