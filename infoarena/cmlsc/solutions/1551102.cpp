#include<fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int l[1026][1026], m, n, sir1[1026], sir2[1026];
void afis (int i, int j)
{
    if(i!=0 && j!=0)
    {
        if(sir1[i]==sir2[j])
        {
            afis(i-1, j-1);
            fout<<sir1[i]<<" ";
        }
        else
            if(l[i][j-1]>l[i-1][j])
                afis(i, j-1);
            else
                afis(i-1, j);
    }
}
int main ()
{
    int i, j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>sir1[i];
    for(i=1; i<=m; i++)
        fin>>sir2[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(sir1[i]==sir2[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j], l[i][j-1]);
    fout<<l[n][m]<<"\n";
    afis (n, m);
    return 0;
}
