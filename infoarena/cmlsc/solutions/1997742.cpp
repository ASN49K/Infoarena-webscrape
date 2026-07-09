#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1026],b[1026], mat[1025][1025];
int main()
{
    int l=0;
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=m; i++)
        in>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
        {
            l++;
            mat[i][j]=l;
        }
    out<<l<<'\n';
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        if(mat[i][j]) out<<a[i]<<" ";
    return 0;
}
