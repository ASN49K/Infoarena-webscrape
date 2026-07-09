#include <stdio.h>
#include <string.h>
using namespace std;
#define NMAX 1025
int n1,n2,sc[NMAX][NMAX],a[NMAX],b[NMAX];

inline int max(int x, int y)
{
	return (x>y?x:y);
}
void citire()
{ 
 FILE *fin=fopen("cmlsc.in","r");
 fscanf(fin,"%d%d",&n1,&n2);
 int i;
 for (i=1;i<=n1;++i) fscanf(fin,"%d",&a[i]);
 for (i=1;i<=n2;++i) fscanf(fin,"%d",&b[i]);
 fclose(fin);
}

int main()
{
 citire();
 memset(sc,0,sizeof(sc));
 int i,j;
 for (i=1;i<=n1;++i)
  for (j=1;j<=n2;++j)
   if (a[i]==b[j]) sc[i][j]=sc[i-1][j-1]+1;
	  else sc[i][j]=max(sc[i-1][j],sc[i][j-1]);
  FILE *fout=fopen("cmlsc.out","w");
  fprintf(fout,"%d\n",sc[n1][n2]);
  int nr=0, sol[NMAX]; 
  for (i=n1,j=n2;i&&j;)
	if (a[i]==b[j]) {sol[++nr]=a[i]; --i;--j;}
        else
         if (sc[i][j-1]<sc[i-1][j]) --i;
            else --j;
  for (i=nr;i;--i) fprintf(fout,"%d ",sol[i]);			
  fclose(fout);
 return 0;
}
