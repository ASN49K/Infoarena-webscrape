#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,t,a,b,c;
int main()
{
    f>>t;
    for(i=0;i<t;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
    }
    return 0;
}
