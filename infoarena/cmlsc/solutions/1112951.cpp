#include <iostream>
#include <fstream>
using namespace std;
int *p1, *p2, *result;
int arr[1025][1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void cmlsc(int n, int m)
{
     for(int i = 1; i<= n; i++)
     {
             for(int j = 1; j<= m; j++)
             {
                     if(p1[i-1] == p2[j-1]) arr[i][j] = arr[i-1][j-1]+1;
                     else arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
             }
     }
     result = new int[arr[n][m]]();
     fout<<arr[n][m]<<endl;
     for(int i = n, j = m, k = 0; i> 0 && j>0; )
     {
             if(arr[i-1][j-1] == arr[i][j]) {i--;j--;}
             else if(arr[i][j] == arr[i-1][j]) i--;
                  else if(arr[i][j] == arr[i][j-1]) j--;
                       else if(arr[i][j] == arr[i-1][j-1] + 1) {result[k] = p1[i-1];i--;j--;k++;};
     }
     for(int i = arr[n][m]-1; i>= 0; i--) fout<<result[i]<<" ";
}
int main()
{
    int n, m;
    fin>>n>>m;
    p1 = new int[n]();
    p2 = new int[m]();
    for(int i = 0; i< n; i++) fin>>p1[i];
    for(int i = 0; i< m; i++) fin>>p2[i];
    cmlsc(n, m);
    return 0;
}
