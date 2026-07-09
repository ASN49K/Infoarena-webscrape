#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int i,a,b,n,r;
int main()
{
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
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
