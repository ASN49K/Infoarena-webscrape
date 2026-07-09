#include<fstream>
using namespace std;
int m,n,i,j,x[1034],v[1034],nr,e[1034];
int main(){
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
        f>>x[i];
        if(n>m){
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(x[i]==v[j]){nr++;e[nr]=x[i];i++;}}
        else{
                for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(v[i]==x[j]){nr++;e[nr]=v[i];i++;}}
        g<<nr<<'\n';
        for(i=1;i<=nr;i++)
            g<<e[i]<<" ";
        return 0;}
