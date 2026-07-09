#include <fstream>
using namespace std;
#define DMAX 300
ifstream fin("adevar.in");
ofstream fout("adevar.out");
int b2[DMAX],n,i,j,use[DMAX],adevar[DMAX][DMAX],minciuna[DMAX][DMAX];
void citeste()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>adevar[i][0];
        for(int j=1;j<=adevar[i][0];j++)
            fin>>adevar[i][j];
        fin>>minciuna[i][0];
        for(int j=1;j<=minciuna[i][0];j++)
            fin>>minciuna[i][j];
    }
}
int verifica()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(!b2[i])
        {
            for(j=1;j<=adevar[i][0];j++)
            {
                if(b2[adevar[i][j]]==1)
                    return 0;
            }
            for(j=1;j<=minciuna[i][0];j++)
            {
                if(b2[minciuna[i][j]]==0)
                    return 0;
            }
        }

    }

    return 1;
}
int afisare()
{

}
void gen()
{
    int i=n,j;
    while(b2[i]==1)
    {
        b2[i]=0;
        i--;
    }
    b2[i]=1;
}
int main()
{
    citeste();
    b2[n]=1;
    while(b2[0]==0)
    {
        gen();
        if(verifica())
        {
            for(i=1;i<=n;i++)
                fout<<b2[i]<<'\n';
            break;
        }
    }
    return 0;
}
