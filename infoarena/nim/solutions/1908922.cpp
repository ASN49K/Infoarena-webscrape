#include <fstream>

using namespace std;

ifstream fin("NIM.in");
ofstream fout("NIM.out");

int n,t,i,x,xorr,j;

int main()
{
    fin>>t;
    for(i=1;i<=t;++i)
    {
        fin>>n;
        xorr=0;
        for(j=1;j<=n;++j)
        {
            fin>>x;
            xorr=xorr^x;
        }
        if(xorr!=0)
            fout<<"DA \n";
        else
            fout<<"NU \n";
    }
    return 0;
}
