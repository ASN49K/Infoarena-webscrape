#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025],b[1025],l[1025][1025],n,m,Max,k;

void afisare(int i, int j)
{
    if (i>0 && j>0 && k<Max)
    {
        k++;
        while (l[i][j]==l[i-1][j])
            i--;
        while (l[i][j]==l[i][j-1])
            j--;
        afisare(i-1,j-1);
        out << b[j] << " ";
    }
}

int main()
{
    in >> n >> m;
    for (int i = 1; i<=n; i++)
        in >> a[i];
    for (int i = 1; i<=m; i++)
        in >> b[i];
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=m; j++)
        {
            if (a[i] == b[j])
                l[i][j] = l[i-1][j-1]+1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
            if (l[i][j]>Max)
                Max = l[i][j];
        }
    out << Max << "\n";
    afisare(n,m);
}
