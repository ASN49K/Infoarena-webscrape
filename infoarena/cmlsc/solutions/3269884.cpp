#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[101],b[101],n,m,viz[101],k,f[101];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}
int main()
{
    citire();
    int l=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(viz[a[i]]==0)
            {
                if(b[i]==a[j])
                {
                    k++;
                    f[k]=b[i];
                    viz[l]=f[k];
                    l++;
                    viz[b[j]]=1;
                    break;
                }
            }
        }
    }
    fout<<k<<endl;
    for(int i=1;i<=k;i++)
        fout<<viz[i]<<" ";
    
}