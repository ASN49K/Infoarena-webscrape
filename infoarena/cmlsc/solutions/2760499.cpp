#include<fstream>
#include<algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1040], b[1040], mat[1040][1040];

void afis(int n, int m)
{
    if(mat[n][m] == 0)
        return;

    if(a[n] == b[m])
    { 
        afis(n-1, m-1);
        g<<a[n]<<" ";
    }
    else if(mat[n-1][m] > mat[n][m-1])
        afis(n-1,m);
    else afis(n,m-1);

   
}

int main()
{
    int n,m;
    f>>n>>m;

    for(int i=1; i<=n; ++i)
        f>>a[i];
    for(int j=1; j<=m; ++j)
        f>>b[j];
    
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
                mat[i][j] = mat[i-1][j-1]+1;

            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }


    g<<mat[n][m]<<"\n";

    afis(n,m);
    g<<"\n";

    return 0;
}
