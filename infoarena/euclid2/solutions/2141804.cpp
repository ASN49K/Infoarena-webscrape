#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        int r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }

    return 0;
}
