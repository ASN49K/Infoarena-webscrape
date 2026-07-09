#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int max(int a, int b)
{
    return (a > b)?a:b;
}
int size(int a[], int m, int b[], int n)
{
    if(m == 0 || n == 0) return 0;
    if(a[m-1] == b[n-1])
    {
              return size(a, m-1, b, n-1)+1;
    }
    else
    {
        return max(size(a, m-1, b, n), size(a, m, b, n-1) );
    }
}
void cmlsc(int a[], int m, int b[], int n, int count)
{
     int tabel[m+1][n+1], out[count], k = 0;
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
     for(int i=count-1; i>=0; i--)
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
    count = size(arr1, m, arr2, n);
    fout<<count<<endl;
    cmlsc(arr1, m, arr2, n, count);
    system("pause");
    return 0;
}
