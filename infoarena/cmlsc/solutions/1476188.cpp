#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, ra, rb, nr, ok;
int a[1050], b[1050], v[1050];

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;++i) fin>>a[i];
    for(int i=1;i<=m;++i) fin>>b[i];
    int g=min(m,n);
    for(int i=1;i<=g;++i){
        ok=1;
        for(int j=rb+1;j<=i && ok;++j)
            if(a[i]==b[j]) v[++nr]=a[i],ok=0,ra=i,rb=j;
        for(int k=ra+1;k<=i && ok;++k)
            if(a[k]==b[i]) v[++nr]=b[i],ok=0,ra=k,rb=i;
    }
    if(n<m){
        for(int i=g+1;i<=m;++i){
            ok=1;
            for(int k=ra+1;k<=n && ok;++k)
                if(b[i]==a[k]) v[++nr]=b[i],ok=0,ra=k;
        }
    }
    if(n>m){
        for(int i=g+1;i<=n;++i){
            ok=1;
            for(int k=rb+1;k<=m && ok;++k)
                if(a[i]==b[k]) v[++nr]=a[i],ok=0,rb=k;
        }
    }
    fout<<nr<<'\n';
    for(int i=1;i<=nr;++i) fout<<v[i]<<' ';





    return 0;
}
