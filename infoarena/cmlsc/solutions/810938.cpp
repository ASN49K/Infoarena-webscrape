#include <fstream>
#define maxim(x, y) ((x > y) ? x : y)
#define NMax 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NMax],b[NMax],lcs[NMax][NMax],sir[NMax];
int nr,m,n;

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
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}

void pd()
{
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        if(a[i]==b[j])
            lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=maxim(lcs[i-1][j],lcs[i][j-1]);
    for(i=m,j=n;i!=0;)
        if(a[i]==b[j])
        {
            sir[++nr]=a[i];
            i--;
            j--;
        }
        else
            if(lcs[i-1][j]<lcs[i][j-1])
                j--;
            else
                i--;
}

void afisare()
{
    int i;
    fout<<nr<<'\n';
    for (i=nr;i!=0;i--)
        fout<<sir[i]<<' ';
    fout.close();
}
