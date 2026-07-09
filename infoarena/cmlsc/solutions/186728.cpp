#include<fstream.h>
#define g 1026
int a[g],b[g],c[g][g];
int main()
 {
  ifstream be ("cmlsc.in");
  ofstream ki ("cmlsc.out");
  int n,m,i,j;
  be>>n>>m;
  for (i=1;i<=n;i++)
     be>>a[i];
  for (i=1;i<=m;i++)
    be>>b[i];
  be.close();
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
  ki<<c[1][1]-1<<'\n';
  i=1;j=1;
  while (i<=n&&j<=m)
   {
    if (a[i]==b[j])
     { ki<<a[i]<<" "; i++;j++; }
    else
       if (c[i][j+1]==c[i+1][j])
	 j++;
       else
	 i++;
   }
  ki<<'\n';
  ki.close();
  return 0;
 }