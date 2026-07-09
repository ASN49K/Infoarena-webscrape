#include <bits/stdc++.h>
#define dim 1040
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[dim],b[dim],d[dim][dim],i,j;
void afis(int i,int j){
    if(d[i][j]==0)
        return;
    if(a[i]==b[j]){
        afis(i-1,j-1);
      //  cout<<i<<" "<<j<<endl;
        fout<<a[i]<<" ";
    }
    else if(d[i][j]==d[i][j-1])
        afis(i,j-1);
    else  afis(i-1,j);
}
int main()
{
   fin>>n>>m;
   for(i=1;i<=n;i++){
    fin>>a[i];
   }
   for(i=1;i<=m;i++)
    fin>>b[i];
   for(i=1;i<=n;i++)
   for(j=1;j<=m;j++){
        if(a[i]==b[j]){
            d[i][j]=d[i-1][j-1]+1;
        }
        d[i][j]=max(d[i][j],max(d[i-1][j],d[i][j-1]));
   }
   fout<<d[n][m]<<"\n";
   afis(n,m);
}
