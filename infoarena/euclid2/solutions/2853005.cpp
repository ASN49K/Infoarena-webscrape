#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, x, y;

int euclid(int x, int y)
{
    if(y==0)
        return x;
    return euclid(y, x%y);
}
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }
    return 0;
}
