#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n,m,v1[1025],v2[1025],M[1025][1025],answer[1025],lim;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i) cin>>v1[i];
    for (int i=1; i<=m; ++i) cin>>v2[i];

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j){
            if (v1[i]==v2[j]) M[i][j]=M[i-1][j-1]+1;
            else M[i][j]=max(M[i-1][j],M[i][j-1]);
        }
    cout<<M[n][m]<<"\n";

    int cauta=M[n][m];
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
            if (M[i][j]==cauta && v1[i]==v2[j]){
                answer[++lim]=v1[i];
                cauta--;
            }
    for (int i=lim; i>=1; --i) cout<<answer[i]<<" ";

    return 0;
}

