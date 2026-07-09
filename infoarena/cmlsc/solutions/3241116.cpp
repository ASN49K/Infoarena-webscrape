#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n,m,ii,v[1026][1026],vv[1026],a[1026],aa[1026];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>vv[i];
    for(int j=1;j<=m;j++)
        cin>>a[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            v[i][j]=((vv[i]==a[j]) ? 1+v[i-1][j-1] : max(v[i-1][j],v[i][j-1]));
    }
    cout<<v[n][m]<< '\n';
    for(int i=n, j=m; i && j;){
                if(vv[i]==a[j]){
                    ii++;
                    aa[ii]=vv[i];
                    i--;
                    j--;
                }
            else
                if(v[i-1][j]<v[i][j-1])
                    j--;
            else
                    i--;
    }
    for(ii;ii;ii--)
        cout<<aa[ii]<< ' ';

    return 0;
}
