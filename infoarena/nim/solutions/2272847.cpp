#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, xorsum;

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        for(int i=1;i<=n;++i)
        {
            int x;
            fin>>x;
            xorsum=xorsum^x;
        }
        if(xorsum) fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
