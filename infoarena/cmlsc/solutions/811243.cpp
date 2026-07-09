#include <fstream>
#define dmax 1050
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
void afisare();

int n,m;
int a[dmax],b[dmax];
int LCS[dmax][dmax];
int OP[dmax][dmax];

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void citire()
{
    int i,j;
    fin>>n>>m;
    for(i=0;i<n;i++)
        fin>>a[i];
    for(j=0;j<m;j++)
        fin>>b[j];
}

void pd()
{
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        for(j=m-1;j>=0;j--)
            {
                if(a[i]==b[j])
                {
                    LCS[i][j]=1+LCS[i+1][j+1];
                    OP[i][j]=1;
                }
                else
                    if(LCS[i+1][j]>LCS[i][j+1])
                        {
                            LCS[i][j]=LCS[i+1][j];
                            OP[i][j]=2;
                        }
                        else
                        {
                            LCS[i][j]=LCS[i][j+1];
                            OP[i][j]=3;
                        }
            }
    }
}

void afisare()
{
    int i=0,j=0;
    fout<<LCS[0][0]<<'\n';
    while(OP[i][j])
    {
        if(OP[i][j]==1)
        {
            fout<<a[i]<<' ';
            ++i; ++j;
        }
        else
            if(OP[i][j]==2)
                ++i;
                else
                    ++j;
    }
    fout.close();
}
