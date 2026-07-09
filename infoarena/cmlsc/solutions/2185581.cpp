#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],sol[1025];
int mat[1025][1025];
int i,j,n,m,imax,nmax,lsol;
int main()
{
   in>>n>>m;

for(i=1;i<=n;i++)
    in>>a[i];
for(j=1;j<=m;j++)
    in>>b[j];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       {
           if(a[i]==b[j])
            mat[i][j]=1+mat[i-1][j-1];
        else
            mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
       }
i=n;j=m;
while(i!=0)
      {
          if(a[i]==b[j])
          {
              sol[++lsol]=a[i];
              i--;
              j--;
          }
          else
            if(mat[i-1][j]<mat[i][j-1])
            j--;

            else
                i--;

      }out<<lsol<<'\n';
for(i=lsol;i>=1;i--)
    out<<sol[i]<<" ";


    return 0;
}
