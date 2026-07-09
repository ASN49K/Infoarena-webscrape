#include<fstream.h>

 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 int x[1025],y[1025],m[1025][1025],i,j,b,a,bin[1025],c;

int main()
{
 f>>a;
 f>>b;
 for(i=1;i<=a;i++)
  f>>x[i];
 for(i=1;i<=b;i++)
  f>>y[i];
 for(i=1;i<=a;i++)
  for(j=1;j<=b;j++)
   if(x[i]==y[j])
    m[i][j]=1+m[i-1][j-1];
   else
    if(m[i-1][j]>m[i][j-1])
     m[i][j]=m[i-1][j];
    else
     m[i][j]=m[i][j-1];
 i=a;
 j=b;
 c=1;
 while(m[i][j])
 {
  if(x[i]==y[j])
  {
   bin[c]=x[i];
   c++;
   i--;
   j--;
  }
  else
   if(m[i][j]==m[i-1][j])
    i--;
    else j--;
 }
  g<<m[a][b]<<"\n";
  c--;
  for(i=c;i>=1;i--)
   g<<bin[i]<<" ";
 f.close();
 g.close();
return 0;

}