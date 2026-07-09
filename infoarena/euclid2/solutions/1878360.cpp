#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid.out");
    int a,b;
    f>>a;
    f>>b;
    if (a == b)
        g<<a;
    while(a != b)
    {
        if(b > a)
            b = b-a;
        else
            a = a - b;
    }
    g<<a;
    f.close();
    g.close();
}
