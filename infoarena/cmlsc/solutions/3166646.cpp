#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025];
void drum(int i,int j,int k){
    if(k!=0){
        if(a[i]==b[j]){
            drum(i-1,j-1,k-1);
            cout<<a[i]<<" ";
        }
        else
            if(d[i-1][j]>d[i][j-1])
                drum(i-1,j,k);
            else
                drum(i,j-1,k);
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    cout<<d[n][m]<<'\n';
    drum(n,m,d[n][m]);
    return 0;
}
