#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int v1[1025],v2[1025],i,j,m,n,lungime[1025][1025],solutie[1025],nr;

int main()
{
 in>>m>>n;
 for(i=1;i<=m;i++)
 {
     in>>v1[i];
 }
 for(j=1;j<=n;j++)
 {
     in>>v2[j];
 }
 for(i=0;i<=m;i++)
 {
     for(j=0;j<=n;j++)
     {
         if(i==0||j==0)
         {
            lungime[i][j]=0;
         }
         else
         {
             if(v1[i]==v2[j])
             {
                 lungime[i][j]=lungime[i-1][j-1]+1;  nr++; solutie[nr]=v1[i];
             }
             else
             {
                 lungime[i][j]=max(lungime[i-1][j],lungime[i][j-1]);
             }
         }
     }
 }
 /*for(i=1;i<=m;i++)
 {
     for(j=1;j<=n;j++)
     {
         out<<lungime[i][j]<<" ";
     }
     out<<'\n';
 }*/ out<<lungime[m][n]<<'\n';
 for(i=1;i<=nr;i++)
 {
     out<<solutie[i]<<" ";;
 }
    return 0;
}
