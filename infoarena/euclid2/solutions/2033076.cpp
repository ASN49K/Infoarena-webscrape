#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid(int &y, int z)
{   int r;
    while(z!=0)
        r=y%z, y=z, z=r;
}
int main()
{   int n, x, y=0, z=0, cmd=0;
    f>>n;
    for(int i=0; i<n*2; i++)
    {
        f>>x;
        if(y==0)
            y=x;
        else
            if(z==0)
            z=x;
        if(y!=0 && z!=0)
          {
            euclid(y,z);
            g<<y<<'\n';
            y=0, z=0;
          }
    }
    return 0;
}
