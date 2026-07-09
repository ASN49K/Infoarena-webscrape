//subsirul de lungime maxima a 2 siruri
#include <fstream.h>
#define MAX 1030
int a[MAX],b[MAX],n,m,x[MAX][MAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void citire()
{
fin>>n>>m;
for (int i=1;i<=n;i++)
   fin>>a[i];
for (int j=1;j<=m;j++)
   fin>>b[j];
fin.close();
}

int maxim(int a,int b){
  if (a>b)
     return a;
  return b;
}

void matrice(){
for (int i=0;i<n;i++)
  for (int j=0;j<m;j++)
     if (a[i+1]==b[j+1]){
	x[i+1][j+1]=1+x[i][j];}
     else
	x[i+1][j+1]=maxim(x[i+1][j],x[i][j+1]);
fout<<x[n][m]<<"\n";
int ii=n,jj=m,r[MAX];
     while (x[ii][jj] > 0) {
	     if (a[ii]==b[jj]) {
		  r[x[ii][jj]]=a[ii];
		   --ii;
		   --jj;
	     }
	     else
	     {
		if (x[ii][jj]==x[ii-1][jj])
		    --ii;
		else
		     --jj;
	     }
    }
for (int q=1;q<=x[n][m];q++)
   fout<<r[q]<<" ";
fout<<"\n";
}

int main(){
citire();
matrice();
fout.close();
return 0;
}
