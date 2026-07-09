#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");



int D[1025][1025];
short a[1025],b[1025];


int main()
{


    int n,m;
      fin>>n>>m;

      for(int i=1;i<=n;i++)
        fin>>a[i];
      for(int i=1;i<=m;i++)
        fin>>b[i];


      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
      {
           D[i][j]=max(D[i-1][j],D[i][j-1]);
           if(a[i]==b[j])
            D[i][j]++;
      }

     int i,j,k=0;
     i=n;
     j=m;



     while(i>=1 && j>=1)
     {
         if(i==1)
         {
             if(D[i][j-1]<D[i][j])
             {
                   k++;
             b[k]=a[i];
             }

             j--;
         }
         else if(j==1)
         {
             if(D[i-1][j]<D[i][j])
             {
                   k++;
             b[k]=a[i];
             }
             i--;
         }
         else

         if(D[i-1][j-1]==D[i][j])
           {
               i--;
               j--;
           }
         else if(D[i-1][j]==D[i][j])
           {
               i--;
           }
         else if(D[i][j-1]==D[i][j])
            {
                j--;
            }
         else
         {
             k++;
             b[k]=a[i];
             i--;
             j--;
         }

     }

     fout<<k<<endl;
     for(int i=k;i>=1;i--)
        fout<<b[i]<<" ";









    return 0;
}
