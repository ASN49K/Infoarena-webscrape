#include <iostream>
#include <fstream>
#define MAX 1025

using namespace std;

int n,m,a[MAX],b[MAX],lung[MAX][MAX],r1,r2,r3,sl,s[MAX];

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        r1=lung[i-1][j-1]+(a[i]==b[j]);
        r2=lung[i-1][j];
        r3=lung[i][j-1];
        lung[i][j]=max(r1,max(r2,r3));
      }
    for(int i=n,j=m;i>=1&&j>=1;){
      if(a[i]==b[j]) s[++sl]=a[i],i--,j--;
      else if(lung[i][j]==lung[i-1][j])i--;
      else j--;
    }
    g<<lung[n][m]<<'\n';
    for(int i=sl;i>=1;i--)g<<s[i]<<" ";
    f.close ();
    g.close ();
    return 0;
}
