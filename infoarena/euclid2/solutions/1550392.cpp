#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned n,r,a,b,i;

int main()
{

    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }
    return 0;
}


