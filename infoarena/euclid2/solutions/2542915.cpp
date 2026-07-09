#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int T,a,b; f>>T;
    while(T)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
        T--;
    }
}
