#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],c[1030][1030],i,j,n,m,sir[1030],k;
int main(){

    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],max(c[i][j-1],c[i-1][j-1]));
        }
    fout<<c[n][m]<<endl;
    for(i=n,j=m;i;){
        if(a[i]==b[j])
        sir[++k]=a[i],i--,j--;
        else
            if(c[i][j-1]>c[i-1][j])
                j--;
                else
                i--;
    }
    for(i=k;i>=1;i--)
        fout<<sir[i]<<" ";
    fin.close();fout.close();
    return 0;
}
