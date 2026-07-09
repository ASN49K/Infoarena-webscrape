#include <fstream>

using namespace std;

int n, m, i, j, a[1025], b[1025], v[1025][1025];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void afis(int i, int j){
    if(v[i][j]!=0){
        if(a[i]==b[j]){
            afis(i-1, j-1);
            fout<<a[i]<<" ";
        }
        else{
            if(v[i-1][j]>v[i][j-1])
                afis(i-1, j);
            else
                afis(i, j-1);
        }
    }
}

int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    //v[i][j] = lungimea celui mai lung subsir comun pana la pozitia i din a[] si pozitia j din b[]
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j], v[i][j-1]);
        }
    fout<<v[n][m]<<"\n";
    afis(n, m);
    return 0;
}
