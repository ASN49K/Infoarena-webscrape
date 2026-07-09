#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,c[1027][1027],a[1027],b[1027],d,n,m;
int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>a[i];
    }
    for(j=1;j<=m;j++){
        fin>>b[j];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[i][j]=c[i-1][j-1]+1;
            }else{
                if(c[i-1][j]>c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
            }
        }
    }
    fout<<c[n][m]<<"\n";
    d=c[n][m];
    i=n;
    j=m;
    while(d!=0){
        if(a[i]==b[j]){
            fout<<a[i]<<" ";
            d--;
            i--;
            j--;
        }else{
            if(c[i-1][j]>c[i][j-1])
                i--;
            else
                j--;
        }
    }
    return 0;
}
