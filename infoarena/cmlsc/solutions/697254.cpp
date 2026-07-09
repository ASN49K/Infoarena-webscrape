#include<fstream>
using namespace std;

  int n,m;
 char V[100],B[100];
int C[100][100];
char D[100][100];
 ifstream f("subsir.in");
 ofstream g("subsir.out");

int drum(char V[100],char D[100][100],int i,int j)
{
    if(i==0 || j==0)
  return 0;
else
{
if(D[i][j]=='d')
{
drum(V,D,i-1,j-1);
g<<V[i]<<" ";
}
 else if(D[i][j]=='s')
    drum(V,D,i-1,j);
 else if(D[i][j]=='i')
    drum(V,D,i,j-1);
 }   }

int main()
{
    f>>n>>m;
 for(int i=1;i<=n;i++)
    f>>V[i];
 for(int i=1;i<=m;i++)
    f>>B[i];

for(int i=1;i<=n;i++)
C[i][0]=0;

for(int i=0;i<=m;i++)
C[0][i]=0;

int i,j;

for(i=1;i<=n;i++)
{
 for(j=1;j<=m;j++)
 {

   if(V[i]==B[j])
 {
 C[i][j]=C[i-1][j-1]+1;
 D[i][j]='d';
     }
else
{
    if(C[i-1][j]>=C[i][j-1])
{
C[i][j]=C[i-1][j];
D[i][j]='s';
}
else
{
C[i][j]=C[i][j-1];
D[i][j]='i';
 }  }
 }}

g<<C[n][m]<<endl;
drum(V,D,n,m);

f.close();
f.close();
    return 0;
    }
