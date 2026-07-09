#include <fstream>

using namespace std;
int mat[1030][1030],a[1026], b[1026], rez[1026];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, i, j, cnt=0;
    cin>>n>>m;
    for (j=1;j<=n;j++) {
        cin>>a[j];
    }
    for (i=1;i<=m;i++) {
        cin>>b[i];
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                mat[i][j]=mat[i-1][j-1]+1;
            }else{
            mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
            }
    }
    }
    cout<<mat[n][m]<<'\n';
    i=n;
    j=m;
    while (i>=1&&j>=1) {
            if (a[i]==b[j]) {
                rez[cnt++]=a[i];
                i--;
                j--;
            }else{
            if (mat[i-1][j]>mat[i][j-1]) {
                i--;
            }else{
            j--;
            }
        }
    }
    for (i=cnt-1;i>=0;i--) {
        cout<<rez[i]<<" ";
    }
    return 0;
}
