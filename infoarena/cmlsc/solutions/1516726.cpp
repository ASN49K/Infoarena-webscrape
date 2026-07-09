#include <iostream>

using namespace std;

int main()
{
//7- cel mai lung subsir comun si pentru nota 10- www.spoj/problems/CPCRP1C/
 int a[100],b[100],s[100][100],n,m,i,j;
 cin>>n;
 cin>>m;
 for(i=1;i<=n;i++)
 cin>>a[i];
 for(j=1;j<=m;j++)
 cin>>b[j];

 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 if(a[i]==b[j]){
 s[i][j]=s[i-1][j-1]+1;
 cout<<a[i]<<" ";
 }
 else s[i][j]=max(s[i-1][j],s[i][j-1]);
 cout<<s[n][m];








    return 0;
}
