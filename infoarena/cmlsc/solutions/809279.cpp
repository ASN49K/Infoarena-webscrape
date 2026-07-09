#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();

int n,m;
int a[1030],b[1030];
int lcs[1030][1030];
int op[1030][1030];

int main()
{
    citire();
    pd();
    return 0;
}


void citire()
{
fin>>n>>m;

for(int i=0;i<n;i++)
    fin>>a[i];
for(int j=0;j<m;j++)
    fin>>b[j];
}


void pd()
{
int i,j;


for(i=n-1;i>=0;i--)
    {
    for(j=m-1;j>=0;j--)
        if(a[i]==b[j])
            {
            lcs[i][j]=1+lcs[i+1][j+1],op[i][j]=1;
            }
            else
            {
            if(lcs[i+1][j]>lcs[i][j+1])
                lcs[i][j]=lcs[i+1][j],op[i][j]=2;
                else
                lcs[i][j]=lcs[i][j+1],op[i][j]=3;
            }
    }

/*
for(i=0;i<=n;i++)
    {for(j=0;j<=m;j++)
        fout<<lcs[i][j]<<' ';
    fout<<'\n';
    }
*/
fout<<lcs[0][0]<<'\n';

for(i=0;i<=n;i++)
    {for(j=0;j<=m;j++)
        if(op[i][j]==1)
            fout<<b[i]<<' ';
    }

}

