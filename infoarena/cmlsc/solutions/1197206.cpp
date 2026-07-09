#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

short c[1030][1030],A[1030],B[1030],sol[1030];
int n,m,i,j,aux(0);

int main () 
{
   cin>>n>>m;
   for (i=1;i<=n;++i) cin>>A[i];
   for (j=1;j<=m;++j) cin>>B[j];
   
   for (i=1;i<=n;++i) 
           for (j=1;j<=m;++j)  
                    if (A[i]==B[j]) c[i][j]=1+c[i-1][j-1];
                             else   c[i][j]=max(c[i-1][j],c[i][j-1]);
   
   for (i=n,j=m;i;)
            if (A[i]==B[j]) sol[++aux]=A[i], --i,--j;
                       else
            if ( max(c[i-1][j],c[i][j-1])==c[i-1][j] ) --i;
                       else --j;
  cout<<aux<<"\n"; 
  for (i=aux;i>=1;--i) cout<<sol[i]<<" ";
   
return 0;
}
