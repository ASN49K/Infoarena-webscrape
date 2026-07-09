#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,d,t;
    f>>a>>b;
    if (a*b==0)
        g<<a+b;
        else
    {
     while(a!=b)
     if(a>b)
     a=a-b;
     else
     b=b-a;

    g<<a;
    }
    f.close();
    g.close();

    return 0;
}
