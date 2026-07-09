#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int m, n, i, j, contor;
int a[1030], b[1030], sir[1030];
int d[1025][1025];


int main()
{
    ifstream fin("cmlsc.in");
    ofstream gout("cmlsc.out");
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=m; ++i)
        fin>>b[i];



    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
                if(a[i]==b[j])  d[i][j]=d[i-1][j-1]+1;
                    else d[i][j]=max(d[i][j-1], d[i-1][j]);
            }

    gout<<d[n][m]<<"\n";


    i=n; j=m;
    while(i>=1 && j>=1)
        {
            if(a[i]==b[j])
                {
                    sir[++contor]=a[i];
                    i--; j--;
                }
                else if(d[i-1][j]<d[i][j-1]) j--;
                    else i--;
        }


    for(i=contor; i>=1; i--)
        gout<<sir[i]<<" ";





    return 0;
}
