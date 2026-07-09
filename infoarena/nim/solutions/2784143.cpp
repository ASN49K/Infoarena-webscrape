#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
const int nmax=1e4;
int v[nmax+5];
int main()
{
    int t,n,i,j,r,a;
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>n>>a;
        r=a;
        for(j=1;j<n;j++)
        {
            in>>a;
            r^=a;
        }
        if(r)
            out<<"DA";
        else
            out<<"NU";
    }
    return 0;
}
