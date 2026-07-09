#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if(!b)
        return a;
    else return euclid(b, a%b);
}


int main()
{
    int T,a,b;
    f>>T;
    for(;t;t--)
    {
        f>>a>>b;
        euclid(a,b);
    }
    return 0;
}
