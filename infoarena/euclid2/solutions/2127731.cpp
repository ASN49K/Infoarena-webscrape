#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(int a,int b)
{
    int rest;
    if(a < b)
    {
        rest = a;
        a = b;
        b = rest;
    }
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    }while(rest != 0);
    g<<a<<"\n";
}

int main()
{
    int nr,a,b;
    f>>nr;
    for(int i = 0;i < nr;i++)
    {
        f>>a>>b;
        cmmdc(a,b);
    }
    f.close();
    g.close();
    return 0;
}
