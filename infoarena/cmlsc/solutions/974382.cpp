#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
const int LEN = 1025;
int a[LEN], b[LEN];
ofstream g("cmlsc.out");
void afisDrum(int d[LEN][LEN], int i, int j)
{

    if(i==0 || j==0)
        return;
    else if (d[i][j] == 3)
    {
        afisDrum(d, i-1, j-1);
        g<<a[i]<<" ";

    }
    else if(d[i][j] == 2)
    {
        afisDrum(d, i-1, j);
    }
    else afisDrum(d, i, j-1);
}
int main()
{
    int n,m,i,j, c[LEN][LEN], d[LEN][LEN];
    ifstream f("cmlsc.in");


    f>>m>>n;

    for(i=1;i<=m;i++)
    {
        f>>a[i];
    }

    for(i=1;i<=n;i++)
    {
        f>>b[i];
    }

    for(i=1;i<=m;i++)
        c[i][0] = 0;

    for(i=1;i<=n;i++)
        c[0][i] = 0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                d[i][j] = 3;
            }
            else
            {
                if(c[i-1][j] >= c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    d[i][j] = 2;
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    d[i][j] = 1;
                }
            }
        }
    }

    g<<c[m][n]<<endl;

    afisDrum(d, m, n);

    return 0;
}
