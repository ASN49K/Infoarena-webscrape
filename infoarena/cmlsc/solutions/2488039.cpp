#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int d[1200][1200],maxim=-120000,a[1200],b[1200],m,n,c,sol[1200];

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=m;i++){
        fin>>b[i];
    }



    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                d[i][j]=1+d[i-1][j-1];
            }
            else{
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }

        }
    }

    //if(d[n][m]==310){
       // d[n][m]++;
    //}
    int i=n;
    int j=m;
    while(i&& j){
        if(a[i]==b[j]){
            c++;
            sol[c]=a[i];
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



    fout<<d[n][m]<<"\n";
    for(int i=d[n][m];i>=1;i--){
        fout<<sol[i]<<" ";
    }
}
