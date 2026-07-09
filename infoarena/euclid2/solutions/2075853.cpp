#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");

    int a,b,r;
    f>>a>>b;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    g<<b;


    return 0;
}
