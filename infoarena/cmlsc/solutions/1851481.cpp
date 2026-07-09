#include <fstream>
#define nmax 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int l[nmax][nmax],x[nmax],y[nmax],n,m;

void Citire()
{int i;
fin>>n>>m;
for(i=1;i<=n;i++) fin>>x[i];
for(i=1;i<=m;i++) fin>>y[i];
}

void Dinamica()
{int i,j;
for(i=0;i<=n;i++)
   for(j=0;j<=m;j++)
      if(i==0||j==0) l[i][j]=0;
      else if(x[i]==y[j]) l[i][j]=1+l[i-1][j-1];
           else l[i][j]=max(l[i-1][j],l[i][j-1]);
}

void Afisare()
{int sol[nmax],k=0,i,j;
fout<<l[n][m]<<"\n";
i=n; j=m;
while(i>0&&j>0)
    if(x[i]==y[j]) {sol[k++]=x[i]; i--; j--;}
    else if(l[i][j]==l[i-1][j]) i--;
         else j--;
for(i=k-1;i>=0;i--) fout<<sol[i]<<" ";
}

int main()
{
Citire();
Dinamica();
Afisare();
   return 0;
}
