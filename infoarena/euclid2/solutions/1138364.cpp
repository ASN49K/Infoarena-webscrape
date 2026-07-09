#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,cmmdc;
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    f>>a>>b;
    while(a!=b)
    {
       if(a>b)
       a=a-b;
       else
       b=b-a;
    }
    cmmdc=a;
    g<<"CMMDC-ul a 2 numere este "<<cmmdc;
    f.close();
    g.close();
    return 0;
}
