#include<fstream>
#include<algorithm>
#define MAX 1030
using namespace std;

short LCS[MAX][MAX],a[MAX],b[MAX],n,m;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
    fin.close();
}

void Rezolvare()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
}
void Afisare(int lin,int col)
{
    if(lin!=0 && col!=0)
    {
        if(a[lin]==b[col])
        {
            Afisare(lin-1,col-1);
            fout<<a[lin]<<" ";
        }
        else
        {
            if(LCS[lin-1][col]>LCS[lin][col-1])
                Afisare(lin-1,col);
            else
                Afisare(lin,col-1);
        }
    }
}
int main()
{
    Citire();
    Rezolvare();
    fout<<LCS[n][m]<<"\n";
    Afisare(n,m);
    fout<<"\n";
    fout.close();
    return 0;
}
