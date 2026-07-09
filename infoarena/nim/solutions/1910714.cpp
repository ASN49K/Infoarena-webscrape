#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int n,t,xo,i,a;
    fin>>t;
    while(t--)
    {
        fin>>n;
        xo=0;
        for(i=1;i<=n;i++)
        {
            fin>>a;
            xo^=a;
        }
        if(xo==0) fout<<"NU\n";
        else fout<<"DA\n";
    }
}
