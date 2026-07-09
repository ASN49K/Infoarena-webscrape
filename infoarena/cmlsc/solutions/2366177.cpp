#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m, i, j, lg[1030][1030], a[1030], b[1030], hm[1030][1030], of;
int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (i=1; i<=m; i++)
        fin>>b[i];
    for (i=1; i<=n+1; i++)
        lg[i][m+1]=0;
    for (j=1; j<=m+1; j++)
        lg[n+1][j]=0;
    for (i=n; i>=1; i--)
        for (j=m; j>=1; j--)
    {
        if (a[i]==b[j])
        {
            lg[i][j]=1+lg[i+1][j+1];
            hm[i][j]=1;
        }
        else
        {
            if (lg[i][j+1]>lg[i+1][j])
            {
                lg[i][j]=lg[i][j+1];
                hm[i][j]=2;
            }
            else
            {
                lg[i][j]=lg[i+1][j];
                hm[i][j]=3;
            }
        }
    }
    fout<<lg[1][1]<<'\n';
    of=lg[1][1];
    i=1; j=1;
    while (of>0)
    {
        if (hm[i][j]==1)
        {
            fout<<a[i]<<' ';
            of--;
            i++;
            j++;
        }
        if (hm[i][j]==2)
            {
                j++;
            }
        if (hm[i][j]==3)
            i++;
    }
    return 0;
}
