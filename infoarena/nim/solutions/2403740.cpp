#include <fstream>

using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
long long t,par,n,i,sx,x;
int main()
{
    fin>>t;
    for(par=1;par<=t;par++)
    {
        fin>>n;
        for(i=1;i<=n;i++)
            {
                fin>>x;
                if(i==1)
                    sx=x;
                else
                    sx^=x;
            }
        if(sx)
            fout<<"DA"<<'\n';
        else
            fout<<"NU"<<'\n';
    }
    return 0;
}
