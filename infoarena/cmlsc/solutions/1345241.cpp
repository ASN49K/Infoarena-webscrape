#include<fstream>
#include<algorithm>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,a[1030],b[1030],c[1030],mx[1030][1030],i,j,k;

main(void)
{
   cin>>n>>m;
   for(i=1;i<=n;++i)cin>>a[i];
   for(i=1;i<=m;++i)cin>>b[i];
   
   for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
         if(a[i]==b[j])mx[i][j]=mx[i-1][j-1]+1;
         else mx[i][j]=max(mx[i-1][j],mx[i][j-1]);
   
   i=n;
   j=m;
   while(j!=0 || i!=0){
         if(a[i]==b[j])c[++k]=a[i],--i,--j; 
         else if(mx[i][j-1]>mx[i-1][j])--j;
         else --i;
         }
   cout<<k<<'\n';
   for(i=k;i>=1;--i)cout<<c[i]<<' ';
}
