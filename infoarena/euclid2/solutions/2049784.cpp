#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int a,b,t;
    f>>t;
    for(int i=0 ; i<t;i++)
    {
       f>>a>>b;
       g<<euclid(a, b);
       g<<"\n";
    }
    return 0;
}
