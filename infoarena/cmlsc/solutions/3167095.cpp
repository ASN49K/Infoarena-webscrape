#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],cont,rez[1025],sj=1;
bool ok;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        ok=false;
        for(int j=sj; j<=m && ok==false; j++)
        {
            if(a[i]==b[j])
            {
                rez[cont]=a[i];
                cont++;
                sj=j;
                ok=true;
            }
        }
        ok=false;
    }
    fout<<cont<<endl;
    for(int i=0; i<cont; i++)
        fout<<rez[i]<<" ";
    return 0;
}
