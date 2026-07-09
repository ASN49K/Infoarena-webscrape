#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b,i,r;
    f>>t;
    ///Euclid scaderi
    /*for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(a!=b)
            if(a>b)a=a-b;
            else b=b-a;
        g<<a<<"\n";
    }*/
    ///Euclid impartiri
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }
        while(r!=0);
        g<<a<<"\n";
    }
    f.close();
    g.close();
}

