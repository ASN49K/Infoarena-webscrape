#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b,a%b);
}

int main()
{
    int a,b;
    f>>a>>b;
    g<<euclid(a,b);
}
