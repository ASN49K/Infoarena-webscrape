#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,a,b;
    bool gata;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        gata=0;
        while(gata==0)
        {
           // if(a==1 || b==1 || a==b){if(b==1)g<<a<<'\n';if(a==1)g<<b<<'\n';gata=1;}
            if(a>b)a-=b;
            else b-=a;
            if(a==b){g<<a<<'\n';gata=1;}
        }
    }
    f.close();
    g.close();
}
