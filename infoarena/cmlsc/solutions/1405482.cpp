#include <fstream>

using namespace std;
int maxim(int a,int b)
{
    if (a>b) return a;
    else return b;
}
int sol[1025][1025];
int main()
{   ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m, a[1025], b[1025],i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           if(a[i]==b[j])
               sol[i][j]=1+sol[i-1][j-1];
           else sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
    // soltia(adica lungimea celui mai lung subsir comun este sol[n][m];

    int v[1025],k;
    k=sol[n][m];
    fout<<k<<endl;
    i=n;j=m;
    //pun soltia in vectorul v
    while(sol[i][j]!=0)
    {
        if (sol[i][j]==1+sol[i-1][j-1])
        {
            v[k]=a[i];
            k--;
            i--;j--;
        }
        else
        if (sol[i][j]==sol[i-1][j]) i--;
               else if (sol[i][j]==sol[i][j-1]) j--;
    }
            //afisam vectorul v
    k=sol[n][m];
    for(i=1;i<=k;i++)
          fout<<v[i]<<" ";




    return 0;
}
