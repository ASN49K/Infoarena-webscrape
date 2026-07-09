#include <fstream>
#define NLIM 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NLIM],b[NLIM],sol[NLIM][NLIM]= {0},best,sir[NLIM];
int main()
{
    int n,m;
    fin>>n>>m;
    ///Citirea celor 2 vectori
    for(int i=1; i<=n; ++i)
        fin>>a[i];///Vectorul in care cautam
    for(int j=1; j<=m; ++j)
        fin>>b[j];///Vectorul pe care il cautam
    ///Algoritm cel mai lung subsir crescator
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int cnt=0;
            if(a[i]==b[j])
                cnt++;

            sol[i][j]=max(sol[i-1][j-1]+cnt,max(sol[i][j-1],sol[i-1][j]));
        }


    }

    int i=n,j=m;

    while(i&&j)///Creare vector care retine elementele comune
    {
        if (a[i] == b[j])
        {
            sir[++best] = a[i];
            --i;
            --j;
        }
        else if (sol[i][j-1] < sol[i-1][j])
            --i;
        else
            --j;
    }

    fout<<sol[n][m]<<"\n";
    for(int i=best; i>0; i--)
        fout<<sir[i]<<" ";

    return 0;
}
