#include <fstream>
#include <iostream>

using namespace std;


int n,m,a[1024],b[1024],mat[1024][1024],sol[1024],N;

int main()
{
    int i, j;

    ifstream f("cmlsc.in");

    f>>n>>m;

    for(int i=1;i<=n;i++)
        f>>a[i];
    for (int i=1;i<=m;i++)
        f>>b[i];

        f.close();


    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (a[i] == b[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);

    for (int i=n,j=m; i; )
        if (a[i] == b[j])
            sol[N++] = a[i], i--, j--;
        else if (mat[i-1][j] < mat[i][j-1])
            j--;
        else
            i--;

    ofstream g("cmlsc.out");

    g<<N<<'\n';

   for(int i=N;i;i--)
           g<<sol[i-1]<<" ";

    return 0;
}
