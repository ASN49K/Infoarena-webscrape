#include <iostream>
#include <fstream>
using namespace std;
#define maxi 1024
//#define verif_max(a, b) ((a > b)? a : b)
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[maxi], b[maxi], c[maxi];
int v[maxi][maxi];


int main()
{
   int m, n;
   fin >> m >> n;
   for(int i = 0; i < m; i++)
   {
         fin >> a[i];
   }

   for(int i = 0; i < n; i++)
   {
       fin >> b[i];
   }
   int cnt = 0;
   for(int i = 1; i <= m; i++)
   {
       for(int j = 1; j <= n; j++)
       {
           if(a[i-1] == b[j-1])
           {
               v[i][j] = 1 + v[i-1][j-1];
           }
           else{
               v[i][j] = max(v[i-1][j], v[i][j-1]);
           }
       }
   }

   int i = m, j = n;
   while(i >= 1 && j >= 1)
   {
       if(a[i-1] == b[j-1])
       {
           c[cnt++] = a[i-1];
           i--;
           j--;
       }
       else
       {
           if(v[i-1][j] > v[i][j-1])
           {
               i--;
           }
           else
           {
               j--;
           }
       }
   }
   fout << v[m][n] << endl;
   for(int i = cnt-1; i >= 0; i --)
   {
       fout << c[i] << " ";
   }
   return 0;
}
