#include <iostream>
#include <cstdint>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
uint16_t a[1024], b[1024], c[1024];
uint16_t v[1024][1024];


int main()
{
   uint16_t m, n;
   fin >> m >> n;
   for(int i = 0; i < m; i++)
   {
         fin >> a[i];
   }

   for(int i = 0; i < n; i++)
   {
       fin >> b[i];
   }
   uint16_t cnt = 0;
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
   fout << v[m][n] << endl;
   uint16_t i = m, j = n;
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
   for(int i = cnt-1; i >= 0; i --)
   {
       fout << c[i] << " ";
   }
   return 0;
}
