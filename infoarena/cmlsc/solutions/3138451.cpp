#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int M[1025][1025],n,m,nr,answer[1025],l;

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

    int cauta=M[n][m];
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
            if (M[i][j]==cauta && M[i][0]==M[0][j]){
                answer[++l]=M[i][0];
                cauta--;
            }
    for (int i=l; i>=1; --i) cout<<answer[i]<<" ";

    return 0;
}
