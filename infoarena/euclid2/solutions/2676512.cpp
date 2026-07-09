#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int Euclid(int a, int b)
{
    int rest;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}
int main()
{
    int T;
    int a, b;
    f>>T;
    while(T)
    {
        f>>a>>b;
        g<<Euclid(a,b)<<endl;
        T--;
    }
    return 0;
}
