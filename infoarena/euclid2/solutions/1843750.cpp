#include <fstream>

using namespace std;

ifstream inf("euclid2.in");
ofstream outf("euclid2.out");

int euclid(int , int);
int t, x, y;

int main()
{
    inf>>t;
    for(int i=1; i<=t; i++)
    {
        inf>>x>>y;
        outf<<euclid(x, y)<<'\n';
    }

    return 0;
}

int euclid(int a, int b)
{
    while (a != b)
    {
        if (a > b)
           a = a - b;
        else
           b = b - a;
    }
    return a;
}
