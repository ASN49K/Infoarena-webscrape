#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{

    int a,b,t,T;
    f>>T;
    for (int i=1;i<=T;i++)
    {
    f>>a>>b;
    while (b!=0)
    {
       t=b;
       b=a%b;
       a=t;
    }
    g<<a<<endl;
    }
}
