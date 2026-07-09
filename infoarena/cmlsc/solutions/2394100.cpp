#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m, vn[1027], vm[1027], a[1028][1028], sol[1027], k;
int main()
{
     fin>>n>>m;
     for(int i=1; i<=n; i++)fin>>vn[i];
     for(int j=1; j<=m; j++)fin>>vm[j];
     for(int i=1; i<=n; i++)
     {
         for(int j=1; j<=m; j++)
         {
             if(vn[i]==vm[j])
             {
                 a[i][j]=a[i-1][j-1]+1;
             }
             else
             {
                 a[i][j]=max(a[i-1][j], a[i][j-1]);
             }
         }
     }
     fout<<a[n][m]<<"\n";
     k=a[n][m];
     int i=n, j=m;
     while(i>0 && j>0)
     {
         while(j>0 && a[i][j]==a[i][j-1])j--;
         while(i>0 &&a[i][j]==a[i-1][j])i--;
         sol[k]=vn[i];
         k--;
         i--;
         j--;
     }
     for(int i=1; i<=a[n][m]; i++)fout<<sol[i]<<" ";
    return 0;
}
