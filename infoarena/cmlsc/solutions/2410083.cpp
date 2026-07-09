#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int vn[1027], vm[1027], n, m, a[1027][1027];
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
                a[i][j]=1+a[i-1][j-1];
            }
            else
            {
                a[i][j]=max(a[i][j-1],a[i-1][j] );
            }
        }
    }
    fout<<a[n][m]<<"\n";
    int i=n, j=m;
    int k=0;
    int vect[1027];
    while(i>=1 && j>=1)
    {
        while(j>=1 && a[i][j]==a[i][j-1])j--;
        while(i>=1 && a[i][j]==a[i-1][j])i--;
        vect[k]=vn[i];
        k++;
        i--;
        j--;

    }
    for(int i=a[n][m]-1; i>=0; i--)fout<<vect[i]<<" ";
    return 0;
}
