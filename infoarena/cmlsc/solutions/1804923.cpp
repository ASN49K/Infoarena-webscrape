#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],d[1030][1030],sol[1030],n,m,i,j,k;
int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    fout<<d[n][m]<<"\n";
    i=n;
    j=m;
    k=d[n][m];
    while(k!=0){
        if(a[i]==b[j]){
            sol[k]=a[i];
            k--;
            i--;
            j--;
        }
        else{
            if(d[i-1][j]>d[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for(i=1;i<=d[n][m];i++)
        fout<<sol[i]<<" ";
    return 0;
}
