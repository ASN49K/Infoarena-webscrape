#define nMax 1024
#include <fstream>
#include <iomanip>

using namespace std;

 ifstream x ("cmlsc.in");
 ofstream y ("cmlsc.out");

 int n,m;
 int A[nMax],B[nMax];
 int map[nMax+1][nMax+1];

int main()
{
    int i,j;

    x>>n>>m;

    for(i=1;i<=n;i++)
        x>>A[i];
    for(i=1;i<=m;i++)
        x>>B[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(A[i]==B[j])
                map[i][j]=max(map[i-1][j],map[i-1][j-1]+1);
            else
                map[i][j]=max(map[i-1][j],map[i][j-1]);
/*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            y<<setw(3)<<map[i][j];
        y<<'\n';
    }
    y<<'\n';
*/
    y<<map[n][m]<<'\n';

    for(i=0;i<m;i++)
        if(map[n][i+1]!=map[n][i])
            y<<B[i+1]<<' ';
    y<<'\n';

    return 0;
}
