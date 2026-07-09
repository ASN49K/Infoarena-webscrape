#include <iostream>
#include <fstream>
#define MAX 1040

using namespace std;

int n,m,sz;
int a[MAX],b[MAX],v[MAX];
int ans[MAX][MAX];

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
      ans[i][j]=max(ans[i][j],ans[i-1][j-1]+(a[i]==b[j]));
      ans[i][j]=max(ans[i][j],ans[i-1][j]);
      ans[i][j]=max(ans[i][j],ans[i][j-1]);
    }
    for(int i=n,j=m;i&&j;)
      if(a[i]==b[j])v[++sz]=a[i],i--,j--;
      else if(ans[i][j]==ans[i-1][j])i--;
      else j--;
    g<<sz<<'\n';
    for(int i=sz;i;i--)g<<v[i]<<" ";
    f.close ();
    g.close ();
    return 0;
}
