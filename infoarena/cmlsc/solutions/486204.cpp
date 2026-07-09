#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030],b[1030],mat[1030][1030],d[1030],n,m,l,max1;

void citire() {
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    fin.close();
}

void ask() {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
    max1=mat[n][m];
    int i=n,j=m;
    while(i && j) {
        if(a[i]==b[j]) {
            d[l++]=a[i];
            i--,j--;
        }
        else
            if(mat[i][j-1]>mat[i-1][j])
                j--;
            else
                i--;
    }
}

void afis() {
    fout<<max1<<"\n";
    for(int i=l-1;i>=0;i--)
        fout<<d[i]<<" ";
    fout.close();
}

int main()
{
    citire();
    ask();
    afis();
    return 0;
}
