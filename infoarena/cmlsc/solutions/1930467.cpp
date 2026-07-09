#include <fstream>
#include <vector>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
vector <short>a(1024);
vector <short>b(1024);
int matrice[1025][1025];

void generare_tablou()
{
    for(int i=0;i<max(n,m);i++)
    {
        matrice[i][0]=0;
        matrice[0][i]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
                matrice[i][j]=matrice[i-1][j-1]+1;

            else
                matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
        }
}

void parcurgere()
{
    int terminat=false;
   g<<matrice[n][m]<<"\n";
   int i=n,j=m,l=matrice[n][m];
   vector <int> s(1024);
   while(l!=0)
   {
       if(matrice[i-1][j-1]==matrice[i][j])i--,j--;
       else if(matrice[i-1][j]==matrice[i][j])i--;
       else if(matrice[i][j-1]==matrice[i][j])j--;
       else {
            s[l-1]=a[i-1];
           l--;
           i--;j--;
            }
   }
   l=matrice[n][m];
   for(i=0;i<l;i++)
   {
       g<<s[i]<<" ";
   }
}
int main()
{


    f>>n>>m;
    for(int i=0;i<n;i++)
        f>>a[i];
    for(int i=0;i<m;i++)
        f>>b[i];
    generare_tablou();
    parcurgere();
    f.close();
    g.close();
}
