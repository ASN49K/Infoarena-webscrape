#include <bits/stdc++.h>
#define DMAX 1030

using namespace std;
ifstream fin("cmlcs.in");
ofstream fout("cmlcs.out");

int a[DMAX];
int b[DMAX];
int unde[DMAX][DMAX];
int lgmax[DMAX][DMAX];
int n,m,i,j;
int main()
{ //citire
  fin>>n;
  for(i=1;i<=n;i++)
     fin>>a[i];
  fin>>m;
  for(i=1;i<=m;i++)
     fin>>b[i];
  for(i=n;i>0;i--)
     for(j=m;j>0;j--)
        if(a[i]==b[j])
          {lgmax[i][j]=1+lgmax[i+1][j+1];
           unde[i][j]=1;
          }
          else
            if(lgmax[i+1][j]>lgmax[i][j+1])
              {lgmax[i][j]=lgmax[i+1][j];
               unde[i][j]=2;
              }
              else
              {lgmax[i][j]=lgmax[i][j+1];
               unde[i][j]=3;
              }
 //afisare
 fout<<lgmax[1][1]<<'\n';
 i=1;j=1;
 while(i<=n && j<=m)
      {if(unde[i][j]==1)
         {fout<<a[i]<<' ';
          i++;
          j++;
         }
         else
            if(unde[i][j]==2)
              i++;
              else
                j++;

      }
 fout.close();
 return 0;
}
