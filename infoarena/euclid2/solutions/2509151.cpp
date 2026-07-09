#include <iostream>
#include <fstream>

#define NMAX 1024

using namespace std;

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
    int n,a,b;
    f>>n;
    while(n--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }

    return 0;
}
