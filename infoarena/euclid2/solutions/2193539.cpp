#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int x, a, b, rest;
    f>>x;
    for(int i=1; i<=x; i++)
    {
    f>>a>>b;
    while(b)
    {
    rest=a%b;
    a=b;
    b=rest;
    }
    g<<a<<endl;
    }
    return 0;
}
