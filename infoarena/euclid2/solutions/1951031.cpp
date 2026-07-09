#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, i, a, b;
int euclid(int x, int y)
{
    int c;
    while(y)
    {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}
int main()
{
    fin>>T;
    for(i = 0; i < T; ++i)
    {
        fin>>a>>b;
        fout<<euclid(a, b)<<'\n';
    }
    return 0;
}
