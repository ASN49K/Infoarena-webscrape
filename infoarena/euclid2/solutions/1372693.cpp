#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int x , int y)
{
    int z;
    while(y)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int main()
{
    int n,x,y,i;
    fin>>n;
    for(i=1 ; i<=n ; ++i)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }

return 0;
}
