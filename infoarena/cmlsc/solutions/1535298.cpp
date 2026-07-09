#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],c[1025][1025];
void afisare (int i,int j)
{ if(i>=1&&j>=1)
  if(a[i]!=b[j]) if(c[i-1][j]>c[i][j-1]) afisare(i-1,j);
                 else afisare (i,j-1);
  else {afisare(i-1,j-1);
       g<<a[i]<<" ";
       }

}
int main()
{ int i,j;
 f>>m>>n;
 for(i=1;i<=m;i++)
    f>>a[i];
 for(i=1;i<=n;i++)
    f>>b[i];
 c[0][0]=0;
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
 else if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
       else c[i][j]=c[i][j-1];
       g<<c[m][n]<<endl;
    afisare(m,n);
    return 0;
}
