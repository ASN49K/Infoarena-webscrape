#include <fstream>
using namespace std;
#define maxn 1025
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[maxn],b[maxn],mat[maxn][maxn];


void lcs(int m, int n){
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
        }
}
void readlcs(int m, int n,int cnt){
    if(m==0 || n==0){
        cout<<cnt<<'\n';
        return;
    }
    else if(a[m]==b[n]){
        cnt++;
        readlcs(m-1,n-1,cnt);
        cout<<a[m]<<' ';
    }else if(mat[m-1][n]<mat[m][n-1])
        readlcs(m,n-1,cnt);
    else readlcs(m-1,n,cnt);
    }

int main()
{
    int m,n,cnt=0;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];
    lcs(m,n);
    readlcs(m,n,cnt);
    return 0;
}
