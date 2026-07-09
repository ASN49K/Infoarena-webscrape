# include <fstream>
using namespace std;
int a[1030], b[1030], c[1030][1030], n, m;
ofstream fout ("cmlsc.out");
void citire ()
{
     int i;
     ifstream fin ("cmlsc.in");
     fin>>n>>m;
     for (i=1;i<=n;i++)
         fin>>a[i];
     for (i=1;i<=m;i++)
         fin>>b[i];
}
     
void afis (int i, int j)
{
     if (i!=0 && j!=0)
        if (a[i]==b[j])
           afis (i-1, j-1), fout<<a[i]<<" ";
        else
            if (c[i-1][j]>c[i][j-1])
               afis (i-1, j);
            else
                afis (i, j-1);
}
int main ()
{
    int i, j;
    citire ();
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
    afis (n, m);
    return 0;
}
