#include <iostream>
#include <fstream>
using namespace std;
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
void citire_afis()
{
    ifstream f("euclid2.in");
    int T,a,b;
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }

}
int main()
{
    citire_afis();
    g.close();

    return 0;
}
