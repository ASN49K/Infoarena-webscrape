#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1025],b[1025],v[1025],n,m,sol,i,j,c[1025][1025];

int afisare (int i, int j){
    if(i==0 || j==0)
        return 0;
    else if(a[i]==b[j]){
        afisare(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else if(c[i-1][j]>c[i][j-1])
        afisare(i-1,j);
    else afisare(i,j-1);
}

int main () {
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]!=b[j])
                if(c[i-1][j]>c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
            else
                c[i][j]=c[i-1][j-1]+1;
        }
    }
    afisare(n,m);
}
