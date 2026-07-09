#include <fstream.h>
#define MAX 1026
int a[MAX][MAX];
int sir1[MAX],sir2[MAX];
int n,m;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

void citire()
{
    int i;
    fin>>n>>m;

    for ( i=1 ; i<=n ;i++)
	fin>>sir1[i];

    for ( i=1 ; i<=m ; i++)
	fin>>sir2[i];
}

int max (int a, int b)
{
  if (a>b)
    return a;
  return b;
}


void dinamik()
{
   for ( int i=1 ;i<=n ;i++)
     for ( int j=1; j<=m;j++)
	 if (sir1[i]==sir2[j])
	     a[i][j]=a[i-1][j-1]+1;
	 else
	   a[i][j]=max(a[i][j-1],a[i-1][j]);
}

void afisare()
{
  fout<<a[n][m]<<"\n";

  int i=n,j=m;
  int sirfinal[MAX],numar=0;

  while (a[i][j])
  {
     if ( sir1[i]==sir2[j] )
     {
       sirfinal[numar++]=sir1[i];
       i--;
       j--;
     }
     else
      if ( a[i][j]==a[i-1][j] )
	 i--;
      else
	 j--;
  }

  for (i=numar-1;i>=0;i--)
     fout<<sirfinal[i]<<" ";
  fout<<"\n";

}

int main ()
{
     citire();
     dinamik();
     afisare();
     fin.close();
     fout.close();
     return 0;
}

