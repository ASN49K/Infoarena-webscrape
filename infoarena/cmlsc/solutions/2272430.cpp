#include <bits/stdc++.h>
#define NMAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int lcs[NMAX][NMAX];
char unde[NMAX][NMAX];
int a[NMAX],b[NMAX];
int n,m;

void citire();
void pd();
void afisare();
int main()
{citire();
 pd();
 afisare();
 return 0;
}
void citire()
{int i;
 fin>>n>>m;
 for(i=1;i<=n;i++)
    fin>>a[i];
 for(i=1;i<=m;i++)
     fin>>b[i];
}
void pd()
{int i,j;
 for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
       if(a[i]==b[j])
          {lcs[i][j]=1+lcs[i+1][j+1];
           unde[i][j]='1';
          }
          else
            if(lcs[i+1][j]>lcs[i][j+1])
              {lcs[i][j]=lcs[i+1][j];
               unde[i][j]='2';
              }
              else
                {lcs[i][j]=lcs[i][j+1];
                 unde[i][j]='3';
                }
}
void afisare()
{int i=1,j=1;
 fout<<lcs[1][1]<<'\n';
 while(i<=n && j<=m)
      {if(unde[i][j]=='1')
         {fout<<a[i]<<' ';
          i++;j++;
         }
         else
            if(unde[i][j]=='2')
              i++;
              else
                j++;
      }
 fout<<'\n';
}
