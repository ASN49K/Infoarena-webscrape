#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int M[1025][1025],n,m,nr;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i) cin>>M[i][0];
    for (int i=1; i<=m; ++i) cin>>M[0][i];


    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j){
            if (M[i][0]==M[0][j]) nr++;
            M[i][j]=nr;
        }

    cout<<M[n][m]<<"\n";
    for (int i=1; i<=n; ++i)
    {
        if (M[i][1]>M[i-1][m]) cout<<M[i][0]<<" ";
        for (int j=2; j<=m; ++j)
            if (M[i][j]>M[i][j-1]) cout<<M[i][0]<<" ";
    }
    return 0;
}
