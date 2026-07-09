#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX=1024;
int v1[NMAX+5], v2[NMAX+5];
int d[NMAX+5][NMAX+5];
struct poz
{
    int linie, coloana;
};
int pozitii[NMAX+5][NMAX+5];
vector <int>sol;

int main()
{
    int n, m, i, j;
    poz aux;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];

    //Directii
    //1 -aceeasi linie, dar coloana diferita (j-1)
    //2- aceeasi coloana, dar linie diferita (i-1)
    //3- directie de diagonala (solutie) (i-1) and (j-1)
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=m;j++)
         {
             if(v1[i]==v2[j])
             {
                 d[i][j]=d[i-1][j-1]+1;
                 pozitii[i][j]=3;
             }
             else
             {
                if(d[i-1][j]>d[i][j-1])
                {
                    d[i][j]=d[i-1][j];
                    pozitii[i][j]=2;
                }
                else
                {
                    d[i][j]=d[i][j-1];
                    pozitii[i][j]=1;
                }
             }
         }
     }
     fout<<d[n][m]<<"\n";
     i=n;
     j=m;
     while(i!=0 and j!=0)
     {
        if(pozitii[i][j]==1)
        {
            j=j-1;
        }
        else
        {
            if(pozitii[i][j]==2)
                i=i-1;
            else
            {
                sol.push_back(v1[i]);
                i=i-1;
                j=j-1;
            }
        }
     }
     for(i=sol.size()-1;i>=0;i--)
     {
         fout<<sol[i]<<" ";
     }
    return 0;
}
