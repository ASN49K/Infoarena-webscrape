#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int i, t, x, y, r;

int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>x>>y;
        r=x%y;
        while(r)
        {
            x=y;
            y=r;
            r=x%y;
        }
        fout<<y<<"\n";
    }
    return 0;
}
