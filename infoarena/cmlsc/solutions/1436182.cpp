using namespace std;
#include <fstream>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, l1[1030], l2[1030];
int a[1030][1030]={0}, sol[1030]={0}, lsol=0;
void creare()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(l1[i]==l2[j]) a[i][j]=1+a[i-1][j-1];
                else
                {
                    if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
                        else a[i][j]=a[i][j-1];
                    }
        }
}
void solutie()
{
    int i, j;
    i=n; j=m;
    while(i!=0&&j!=0)
    {
        if(l1[i]==l2[j])
        {
            lsol++;
            sol[lsol]=l1[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1]) i--;
                else j--;
        }
    }
}
int main()
{
    int i, j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>l1[i];
    for(i=1; i<=m; i++)
        f>>l2[i];
    creare();
    solutie();
    g<<lsol<<'\n';
    for(i=lsol; i>=1; i--)
        g<<sol[i]<<' ';
    return 0;
}
