#include <fstream>
#define DIM 1030
using namespace std;

int m,n,a[DIM],b[DIM],len[DIM][DIM],ans[DIM];

int getLCS() {
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++) {
        if(a[i]==b[j])
            len[i][j]=len[i-1][j-1]+1;
        else
            len[i][j]=max(len[i-1][j],len[i][j-1]);
    }
    return len[m][n];
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    fout<<getLCS()<<'\n';
    int i=m,j=n,index=0;
    while(i&&j) {
        if(a[i]==b[j]) {
            ans[index++]=a[i];
            i--,j--;
        }
        else if(len[i-1][j]<len[i][j-1])
            j--;
        else
            i--;
    }
    for(i=index-1;i>=0;i--)
        fout<<ans[i]<<" ";
    return 0;
}
