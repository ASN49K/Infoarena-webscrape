#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int x, int y)
{
    int c=0;
    while(y)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
int main()
{
    int n, x, y;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<euclid(x, y)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
