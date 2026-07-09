#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("cmlsc.out");
int m,n,a[1025],b[1025],c[1025][1025];

void gaseste_subsir() {
    int maxim=0,max_i=0,max_j=0;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++) {
        if(a[i]==b[j])
            c[i][j]=1+c[i-1][j-1];
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    int ll=m,cc=n,index=0,rasp[1025];
    while(ll||cc) {
        if(ll&&cc&&a[ll]==b[cc]) {
            rasp[index]=a[ll];
            index++;
            ll--;
            cc--;
        }
        else if(ll&&c[ll-1][cc]==c[ll][cc])
            ll--;
        else if(cc&&c[ll][cc-1]==c[ll][cc])
            cc--;
    }
    fout<<c[m][n]<<'\n';
    for(int i=c[m][n]-1;i>=0;i--)
        fout<<rasp[i]<<" ";
    fout<<'\n';
}

int main()
{
    ifstream fin("cmlsc.in");
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    gaseste_subsir();
    return 0;
}
