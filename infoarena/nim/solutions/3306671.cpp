#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int k,n,r;

int main()
{
    fin>>k;
    for(int i=1;i<=k;i++)
    {
        fin>>n;
        r=0;
        for(int j=1;j<=n;j++)
        {
            int x;
            fin>>x;
            r=r^x;
        }
        if(r==0)    fout<<"NU"<<endl;
        else fout<<"DA"<<endl;
    }
    return 0;
}
