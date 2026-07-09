#include <fstream>
#define NMAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,a[NMAX],b[NMAX],m,LCS[NMAX][NMAX];
char unde[NMAX][NMAX];
void citire();
void pd();
void afisare();
int main()
{
    citire();
    pd();
    afisare();
    return 0;
}
void citire()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
}
void pd()
{
  int i,j;
  for(i=n;i>=1;i--)
    for(j=n;j>=1;j--)
       if(a[i]==b[j]) ///cazul 1
          {
            LCS[i][j]=1+LCS[i+1][j+1];
            unde[i][j]='1';
          }
        else
            if(LCS[i+1][j]>LCS[i][j+1]) ///cazul 2
        {
            LCS[i][j]=LCS[i+1][j];
            unde[i][j]='2';
        }
            else
                if(LCS[i][j+1]>LCS[i+1][j]) ///cazul 3
            {
                LCS[i][j]=LCS[i][j+1];
                unde[i][j]='3';
            }

}
void afisare()
{
    int i,j;
    fout<<LCS[1][1]<<'\n';
    i=1; j=1;
    while(i<=n && j<=m)
    {
        if(unde[i][j]=='1')
            fout<<a[i]<<' ',i++,j++;
        else
            if(unde[i][j]=='2')
              i++;
            else
                j++;
    }
}
