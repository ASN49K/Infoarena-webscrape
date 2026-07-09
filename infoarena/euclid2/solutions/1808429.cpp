#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,x,y,rest;

int main()
{
    fin>>n;

    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;

        while(x>0)
        {
            rest=y%x;
            y=x;
            x=rest;
        }

        fout<<y<<'\n';
    }

    return 0;
}
