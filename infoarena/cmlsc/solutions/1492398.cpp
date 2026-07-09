#include <fstream>
#include <iostream>
using namespace std;
int x,y,i,j,len;
int C[1024][1024],a[1024],b[1024];
int main()
{
    ifstream intrare ("clmsc.in");
    ofstream iesire ("clmsc.out");
    intrare>>x>>y;
    for (i=1; i<=x; i++)
    {
        intrare>>a[i];
    }
    for (i=1; i<=y; i++)
    {
        intrare>>b[i];
    }
    for (i=1;i<=x;i++)
        for (j=1;j<=y;j++)
        {
            if (a[i]==b[j]) C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=(C[i-1][j]>C[i][j-1] ? C[i-1][j]:C[i][j-1]);
        }
    len=C[x][y];
    iesire<<len<<endl;
    int k=0;
    while (k<len)
    {
        for (i=1;i<=x;i++)
            for (j=1;j<=y;j++)
            {
                if (a[i]==b[j]) {iesire<<a[i]<<" ";k++;}
            }
    }
    return 0;
}
