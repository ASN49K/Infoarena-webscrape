#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int max(int a, int b)
{
    return (a > b)?a:b;
}
void cmlsc(int a[], int m, int b[], int n)
{
     int tabel[m+1][n+1], out[1024], k = 0;
     for(int i=0; i< m+1; i++)
     {
             for(int j = 0; j< n+1; j++)
             {
                     tabel[i][j] = 0;
             }
     }
     for(int i=1; i< m+1; i++)
     {
             for(int j=1; j< n+1; j++)
             {
                     if(a[i-1] == b[j-1]) tabel[i][j] = tabel[i-1][j-1] + 1;
                     else tabel[i][j] = max(tabel[i-1][j], tabel[i][j-1]);
             }
     }
     for(int i=m; i > 0;)
     {
             for(int j = n; j> 0; j--)
             {
                     if(tabel[i-1][j] == tabel[i][j-1])
                     {
                                      if(tabel[i-1][j-1] < tabel[i][j])
                                      {
                                                       out[k] = a[i-1];
                                                       k++;
                                      }
                                      i--;
                                      j--;
                     }
                     else
                     {
                         if(max(tabel[i][j-1], tabel[i-1][j]) == tabel[i][j-1])
                         {
                                               j--;
                         }
                         else i--;
                     }
             }
     }
     fout<<tabel[m][n]<<endl;
     for(int i=k-1; i>=0; i--)
     {
             fout<<out[i]<<" ";
     }
     fout<<endl;
}
int main()
{
    int m, n, count;
    fin>>m>>n;
    int arr1[m], arr2[n];
    for(int i = 0; i< m; i++)
    {
            fin>>arr1[i];
    }
    for(int i = 0; i< n; i++)
    {
            fin>>arr2[i];
    }
    cmlsc(arr1, m, arr2, n);
    return 0;
}
