#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    if(!b)
        return a;
    else
        euclid(b, a % b);
}
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t;
    fin>>t;
    for(int a0; a0<t; a0++)
    {
        int x,y;
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }
    return 0;
}
