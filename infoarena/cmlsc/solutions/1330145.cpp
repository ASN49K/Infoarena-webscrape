#include <fstream>
#define DMAX 1030
using namespace std;

int n, m, a[DMAX], b[DMAX];
int LCS[DMAX][DMAX];
//LCS[i][j]=lungimea subsirului comun maximal care se obtine din elementele an, an-1, ..., ai si bm,bm-1, ..., bj
int lgsol, sol[DMAX];

void citire();
void constr_LCS();
void afisare();

int main()
{
    citire();
    constr_LCS();
    afisare();
    return 0;
}

void citire()
{
    int i;
    ifstream fin ("cmlsc.in");
    fin>>n>>m;
    for (i=1; i<=n; ++i)
        fin>>a[i];
    for (i=1; i<=m; ++i)
        fin>>b[i];
    fin.close();
    return;
}

void constr_LCS()
{
    int i, j;
    for (i=n; i; --i)
        for (j=m; j; --j)
            if (a[i]==b[j])
                LCS[i][j]=1+LCS[i+1][j+1];
                else
                LCS[i][j]=max(LCS[i][j+1], LCS[i+1][j]);
    i=j=1;
    while (LCS[i][j])
        if (a[i]==b[j])
        {
            sol[++lgsol]=a[i];
            ++i; ++j;
        }
            else
            if (LCS[i][j+1]>LCS[i+1][j])
                ++j;
                else
                ++i;
    return;
}

void afisare()
{
    int i;
    ofstream fout ("cmlsc.out");
    fout<<lgsol<<"\n";
    for (i=1; i<=lgsol; ++i)
        fout<<sol[i]<<" ";
    fout<<"\n";
    fout.close();
    return;
}
