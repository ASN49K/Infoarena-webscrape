#include <fstream>
//CMLSC - PROGRAMARE DINAMICA
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire(int dim,int v[])
{
    for(int i=1;i<=dim;i++)
        f>>v[i];
}

int main()
{
    int n,m,a[100],b[100],mx[100],k=0;
    f>>n>>m;
    citire(n,a);
    citire(m,b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                {
                    mx[++k]=a[i];
                }
    g<<k<<endl;
    for(int i=1;i<=k;i++)
        g<<mx[i]<<" ";



    return 0;
}
