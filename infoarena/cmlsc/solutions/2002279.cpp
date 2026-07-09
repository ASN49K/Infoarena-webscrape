#include <fstream>
using namespace std;
int k=0,sb[1030],m,n,a[1030],b[1030];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>m>>n;
    {
        for(int i=1; i<=m; i++) fin>>a[i];
        for(int i=1; i<=n; i++)
        {
            fin>>b[i];
            for(int j=1; j<=m; j++)
            {
                if(b[i]==a[j])
                {
                    k++;
                    sb[k]=a[j];
                }
            }
        }
        fout<<k<<"\n";
        for(int j=1; j<=k; j++) fout<<sb[j]<<" ";
        return 0;
    }
}
