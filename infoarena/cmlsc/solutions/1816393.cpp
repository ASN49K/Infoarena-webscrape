#include <fstream>

using namespace std;

int f(int v[], int start, int n, int k)
{
    for(int i=start;i<=n;i++)
        if(v[i]==k)
            return i;

    return -1;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n,m,i,j,k=0,poz=1,aux;
    fin>>n>>m;
    int a[n],b[m],v[max(n,m)];

    for(i=1;i<=n;i++)
        fin>>a[i];

    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
        if(m>=poz){
            aux=f(b,poz,m,a[i]);
            if(aux!=-1){
                poz=aux;
                v[++k]=b[poz];
            }
        }

    for(i=1;i<=k;i++)
        fout<<v[i]<<" ";

    return 0;
}
