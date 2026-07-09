#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,t,T;
    f>>T;
    while (T)
    {
    f>>a>>b;
    while (b!=0)
    {
       t=b;
       b=a%b;
       a=t;
    }
    g<<a<<endl;
    T--;
    }
}
