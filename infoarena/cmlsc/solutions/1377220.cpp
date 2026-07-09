#include <fstream>
#define DIM 1025
#define maxim(a, b) ((a>b)?a:b)
using namespace std;

short v[DIM], v1[DIM], res[DIM][DIM], l, c, dim, sir[DIM], n, m;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        in>>v[i];
    }
    for(int i=1; i<=m; ++i)
    {
        in>>v1[i];
    }
    for(int l=1; l<=n; ++l)
    {
        for(int c=1; c<=m; ++c)
        {
            if(v[l]==v1[c])
            {
                res[l][c]=res[l-1][c-1]+1;
            }
            else
            {
                res[l][c]=maxim(res[l-1][c], res[l][c-1]);
            }
        }
    }
    out<<res[n][m]<<"\n";
    l=n; c=m; dim=res[n][m];
    while(l&&c)
    {
        if(v[l]==v1[c])
        {
            sir[dim]=v[l];
            l--; c--;
            dim--;
        }
        else
        {
            if(res[l][c]==res[l-1][c])
                l--;
            else c--;
        }
    }
    for(int i=1; i<=res[n][m]; ++i)
    {
        out<<sir[i]<<" ";
    }
    out<<"\n";
    in.close();
    out.close();
    return 0;
}
