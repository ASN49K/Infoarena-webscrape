#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1026],v2[1026],rasp[1026][1026],v[1026];

int main()
{
    int n,m,nr=1;

    fin >> m >> n;
    for (int i=1;i<=m;i++)fin >> v1[i];
    for (int i=1;i<=n;i++)fin >> v2[i];

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (v1[i]==v2[j]) rasp[i][j]=1+rasp[i-1][j-1];
            rasp[i][j]=max(rasp[i][j],rasp[i-1][j]);
            rasp[i][j]=max(rasp[i][j],rasp[i][j-1]);
        }
    fout << rasp[m][n] << endl;

    int i=m,j=n,o=0;

    while(i>=1)
    {
        if (v1[i]==v2[j]){v[o++]=v1[i];i--;j--;}
        else if (rasp[i-1][j]<rasp[i][j-1]) j--;
            else i--;
    }
    for (int i=o-1;i>=0;i--) fout << v[i] << " ";
    return 0;
}
