#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], op[1025][1025], LCS[1025][1025], n, m;

void citire();
void afisare();
void pd();

int main()
{
    citire();
    pd();
    afisare();
}

void citire()
{
    int i;
    fin>>n>>m;
    for(i=0;i<n;i++) fin>>a[i];
    for(i=0;i<m;i++) fin>>b[i];
}

void pd()
{
    int i, j;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            if(a[i]==b[j])
            {
                LCS[i][j]=1+LCS[i+1][j+1]; op[i][j]=1;
            }
            else
            {
                if(LCS[i+1][j]>LCS[i][j+1])
                {
                    LCS[i][j]=LCS[i+1][j]; op[i][j]=2;
                }
                else
                {
                    LCS[i][j]=LCS[i][j+1]; op[i][j]=3;
                }
            }
}

void afisare()
{
    int i=0, j=0;
    fout<<LCS[0][0]<<'\n';
    while(i!=n&&j!=m)
    {
        if(op[i][j]==1)
        {
            fout<<a[i]<<' ';
            i++; j++;
        }
        else
            if(op[i][j]==2)
                i++;
            else
                j++;
    }
}

