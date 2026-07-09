#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,nr;
short a[1030],b[1030],D[1030][1030],subsir[1030];
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                D[i][j]=D[i-1][j-1]+1;
            }
            else{
                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
        }
    }
    while(n!=0 && m!=0){
        if(a[n]==b[m]){
            subsir[++nr]=a[n];
            n--;
            m--;
        }
        else{
            if(D[n-1][m]>D[n][m-1])
                n--;
            else
                m--;
        }
    }
    fout<<nr<<"\n";
    for(int i=nr;i>=1;i--)
        fout<<subsir[i]<<" ";
    return 0;
}
