#include <fstream.h>
#include <iostream.h>

int a[1026],b[1026],c[1026][1026];
int main()
 {
  fstream f1 ("cmlsc.in",ios::in);
  fstream f2 ("cmlsc.out",ios::out);
  int n,m,i,j;
  f1>>n>>m;
  for (i=1;i<=n;i++)
     f1>>a[i];
  for (i=1;i<=m;i++)
    f1>>b[i];
  f1.close();
  for (i=n;i>0;i--)
     for (j=m;j>0;j--)
	{
	 if (a[i]==b[j])
	   c[i][j]=c[i+1][j+1]+1;
	 else
	   if (c[i+1][j]>c[i][j+1])
	     c[i][j]=c[i+1][j];
	   else
	     c[i][j]=c[i][j+1];
	}
  f2<<c[1][1]<<'\n';
  i=1;j=1;
  while (i<=n&&j<=m)
   {
    if (a[i]==b[j])
     { f2<<a[i]<<" "; i++;j++; }
    else
       if (c[i][j+1]==c[i][j])
	 j++;
       else
	 i++;
   }
  f2<<'\n';
  f2.close();
  return 0;
 }
