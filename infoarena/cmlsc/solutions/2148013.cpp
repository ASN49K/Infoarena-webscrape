#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1025], b[1025], n, m, i, j, d[1025][1025], lg[1025][1025];
void afisare(int i, int j)
{
    if(i>0&&j>0)
        if(d[i][j]==1)
        {
            afisare(i-1, j-1);
            fout << a[i] << ' ';
        }
        else if(d[i][j]==2)
            afisare(i-1,j);
        else afisare(i, j-1);

}
int main()
{
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(i=1;i<=m;i++)
        fin >> b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
        {
            lg[i][j]=1+lg[i-1][j-1];
            d[i][j]=1;
        }
        else if(lg[i][j-1]<lg[i-1][j])
        {
            lg[i][j]=lg[i-1][j];
            d[i][j]=2;
        }
        else if(lg[i-1][j]<lg[i][j-1])
        {
            lg[i][j]=lg[i][j-1];
            d[i][j]=3;
        }
    }
    fout << lg[n][m] << '\n';
    afisare(n, m);
    return 0;
}
