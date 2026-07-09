#include <fstream>
#include <algorithm>
#define DMAX 1100

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[DMAX],b[DMAX];
int LCS[DMAX][DMAX];

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
int i;
fin>>n>>m;
for (i=1;i<=n;i++) fin>>a[i];
for (i=1;i<=m;i++) fin>>b[i];
}

void pd()
{
int i,j;
for (i=1,j=m+1;i<=n;i++) LCS[i][j]=0;
for (j=1,i=n+1;j<=m;j++) LCS[i][j]=0;
for (i=n;i>=1;i--)
     for (j=m;j>=1;j--)
          if (a[i]==b[j])
              LCS[i][j]=1+LCS[i+1][j+1];
              else
              LCS[i][j]=max(LCS[i+1][j],LCS[i][j+1]);
}

void afisare()
{
int i=1,j=1;
fout<<LCS[i][j]<<'\n';
while (i!=n+1 && j!=m+1)
       if (a[i]==b[j])
           {
            fout<<a[i]<<' ';
            i++,j++;
           }
           else
           if (LCS[i][j]==LCS[i+1][j])
               i++;
               else
               j++;
fout<<'\n';
}
