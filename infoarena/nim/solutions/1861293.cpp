#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int i,j,t,n,xo,x;
    fin>>t;
    for(j=1;j<=t;j++)
    {
        fin>>n;
        xo=0;
        for(i=1;i<=n;i++)
        {
            fin>>x;
            xo=xo^x;
        }
        if(xo==0)
            fout<<"NU"<<'\n';
        else
            fout<<"DA"<<'\n';
    }
    return 0;
}
