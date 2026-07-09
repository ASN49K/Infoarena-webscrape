#include <fstream>
#define LGMAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[LGMAX],b[LGMAX],n,m;
int unde[LGMAX][LGMAX],lcs[LGMAX][LGMAX];
void citire();
void pd();
void afisare();
int main()
{
    citire();
    pd();
    afisare();
    return 0;
}
void citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void pd()
{
    int i,j;
    for(i=n;i>0;i--)
        for(j=m;j>0;j--)
    {
        if(a[i]==b[j])
        {
            lcs[i][j]=lcs[i+1][j+1]+1;
            unde[i][j]=1;
        }
        else
        {
            if(lcs[i+1][j]>lcs[i][j+1])
            {
                lcs[i][j]=lcs[i+1][j];
                unde[i][j]=2;
            }
            else
            {
                lcs[i][j]=lcs[i][j+1];
                unde[i][j]=3;
            }
        }
    }
}
void afisare()
{
    fout<<lcs[1][1]<<'\n';
    int i=1;
    int j=1;
    while(i<=n&&j<=m)
    {
        if(unde[i][j]==1)
        {
            fout<<a[i]<<' ';
            i++;
            j++;
        }
        else
        {
            if(unde[i][j]==2)
            {
                i++;
            }
            else
                j++;
        }

    }
}
