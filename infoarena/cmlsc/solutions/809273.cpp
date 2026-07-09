#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
void afisare();

int lcs[1000][1000], op[1000][1000], n, m, a[1000], b[1000];
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
    fin >> n >> m;
    for(i=0;i<n;i++)
        fin >> a[i];
    for(i=0;i<m;i++)
        fin >> b[i];
}

void pd()
{
    int i, j;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=i;j--)
        {
            if(a[i]==b[j])
            {
                lcs[i][j]=1+lcs[i+1][j+1];
                op[i][j]=1;
            }
            else
            {
                lcs[i][j]=max(lcs[i+1][j], lcs[i][j+1]);
                if(lcs[i][j]==lcs[i+1][j])
                    op[i][j]=2;
                else
                    op[i][j]=3;
            }
        }
}

void afisare()
{
    int i, j;
    fout << lcs[0][0] << '\n';
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(op[i][j]==1)
                fout << b[j] << ' ';
}

