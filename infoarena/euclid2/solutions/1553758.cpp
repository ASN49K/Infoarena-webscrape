#include <fstream>
using namespace std;
ifstream f("eucl.in");
ofstream g("eucl.out");
int a,b,rest;
int main()
{
    f>>a;
    f>>b;
    while (b)
       {
        rest=a%b;
        a=b;
        b=rest;}
        g<<a;
    return 0;
}
