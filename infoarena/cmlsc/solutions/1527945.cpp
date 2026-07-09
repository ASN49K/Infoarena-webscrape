#include <fstream>

using namespace std;
int i, x, v[1025], a[1025], n, p, nr, maxim, maxim1, w[1025], k;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>p;
    for(i=1;i<=n;i++){
        fin>>x;
        v[x]=1;
        if(maxim<x)
            maxim=x;
    }
    for(i=1;i<=p;i++){
        fin>>x;
        a[x]=1;
        if(maxim<x)
            maxim=x;
    }
    for(i=1;i<=maxim;i++){
        if(a[i]==v[i] && a[i]!=0){
           w[++k]=i;
        }
    }
    fout<<k<<'\n';
    for(i=1;i<=k;i++)
        fout<<w[i]<<" ";
    return 0;
}
