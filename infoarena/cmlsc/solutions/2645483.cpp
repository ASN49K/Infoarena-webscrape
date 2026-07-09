#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1025], b[1025], d[1025][1025], sol[1025];

int main()
{
    int n, m, i, j, k;
    fin>>n>>m;

    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }

    for(i=1; i<=m; i++)
    {
        fin>>b[i];
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }

            else d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }

    fout<<d[n][m]<<"\n";

    i=n;
    j=m;
    k=0;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            k++;
            sol[k]=a[i];

            i--;
            j--;
        }

        else if(d[i][j-1]>d[i-1][j])
        {
            j--;
        }

        else i--;
    }

    for(i=k; i>=1; i--) fout<<sol[i]<<' ';
}
