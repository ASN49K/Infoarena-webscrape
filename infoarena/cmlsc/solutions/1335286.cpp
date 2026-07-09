#include <fstream>
#define DMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[DMAX], b[DMAX];
int LCS[DMAX][DMAX];

void citire();
void LongestCommonSubsequence();

int main()
{
    citire();
    LongestCommonSubsequence();
    return 0;
}

void citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;++i) fin>>a[i];
    for(i=1;i<=m;++i) fin>>b[i];
}

void LongestCommonSubsequence()
{
    int i, j;

    for(i=n;i>=1;--i)
        for(j=m;j>=1;--j)
        {
            if(a[i]==b[j])
                LCS[i][j]=1+LCS[i+1][j+1];
                else
                {
                    if(LCS[i][j+1]>LCS[i+1][j])
                        LCS[i][j]=LCS[i][j+1];
                        else
                            LCS[i][j]=LCS[i+1][j];
                }
        }

    fout<<LCS[1][1]<<'\n';
    for(i=1, j=1;i<=n && j<=m;)
        if(a[i]==b[j])
        {
            fout<<a[i]<<' ';
            ++i; ++j;
        }
            else if(LCS[i+1][j]<LCS[i][j+1]) ++j;
                else ++i;
}
