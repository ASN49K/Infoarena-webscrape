#include <bits/stdc++.h>
#define DMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[DMAX],b[DMAX];
int lg[DMAX][DMAX],unde[DMAX][DMAX];

void citire();

int main()
{int i,j;
 citire();
 for(i=n;i>=1;i--)
     for(j=m;j>=1;j--)
         if(a[i]==b[j])
            {lg[i][j]=1+lg[i+1][j+1];
             unde[i][j]=1;
            }
            else
            if(lg[i+1][j]>lg[i][j+1])
               {lg[i][j]=lg[i+1][j];
                unde[i][j]=2;
               }
               else
               {lg[i][j]=lg[i][j+1];
                unde[i][j]=3;
               }
 fout<<lg[1][1]<<'\n';
 i=j=1;
 while(i<=n && j<=m)
       if(unde[i][j]==1)
          {fout<<a[i]<<' ';
           i++;j++;
          }
          else
          if(unde[i][j]==2)
             i++;
             else
             j++;
 fout.close();
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
