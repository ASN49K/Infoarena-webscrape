#include <iostream>
#include<fstream>
using namespace std;

ifstream f("cmlsc.in") ;
ofstream g("cmlsc.out") ;

int d[1025][1025],n,m,a[1025],b[1025],v[1025] ;

int maxi(int x, int y)
{
    if(x>y) return x ;
      else return y ;
}
int main()
{
   int i,j ;
   f>>n>>m ;
   for(i=1;i<=n;i++) f>>a[i] ;
   for(i=1;i<=m;i++) f>>b[i] ;

   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1] ;
           else d[i][j]=maxi(d[i-1][j],d[i][j-1]) ;
   g<<d[n][m]<<endl ;
   i=n ;
   j=m ;
   int loc=0 ;
   while(i>0&&j>0)
   {
       if(a[i]==b[j])
       {
           loc++ ;
           v[loc]=a[i] ;
           i-- ;
           j-- ;
       }
        else if(d[i-1][j]>d[i][j-1]) i-- ;
           else j-- ;
   }
   for(i=loc;i>=1;i--) g<<v[i]<<" " ;

}
