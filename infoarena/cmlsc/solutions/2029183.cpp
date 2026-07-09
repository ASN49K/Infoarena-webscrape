#include <fstream>
#define vmax 1026
using namespace std;
ifstream fin("cmlcs.in");
ofstream fout("cmlcs.out");

int n,m,k;
int lg[vmax][vmax],cum[vmax][vmax];
int a[vmax],b[vmax],sol[vmax];

void citire();
void calcul();
void solutie();
void afisare();
int main()
{
    citire();
    calcul();
    solutie();
    afisare();
    return 0;
}
void citire()
{
   fin>>n>>m;
   for(int i=1; i<=n; i++)
      fin>>a[i];
   for (int i=1; i<=m; i++)
      fin>>b[i];
}
void calcul()
{
   for (int i=0; i<=n; i++)
      for (int j=0; j<=m; j++)
         {
            if (i==0 || j==0)
               lg[i][j]=0;
            else if (a[i]==b[j])
               {
                  lg[i][j]=1+lg[i-1][j-1];
                  cum[i][j]=1;
               }
             else if (lg[i-1][j]>lg[i][j-1])
                  {
                     lg[i][j]=lg[i-1][j];
                     cum[i][j]=2;
                  }
             else
               {
                  lg[i][j]=lg[i][j-1];
                  cum[i][j]=3;
               }
         }
}
void solutie()
{
   int i=n,j=m,k=lg[i][j];
   while (i && j)
      {
         if (cum[i][j]==3)
               j--;
         else if (cum[i][j]==2)
            i--;
         else
            {
               sol[k]=a[i];
               k--;
               i--;
               j--;
            }

      }
}
void afisare()
{
   fout<<lg[n][m]<<'\n';
   for (int i=1; i<=lg[n][m]; i++)
      fout<<sol[i]<<" ";

}
