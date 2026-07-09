#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int d,i,r,t;
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>d>>i;
        while(i)
        {
            r=d%i;
            d=i;
            i=r;
        }
        fout<<d<<"\n";
    }
    return 0;
}
