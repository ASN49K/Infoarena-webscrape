#include <fstream>
using namespace std;
int vm[1030],vn[1030],vr[1030];
int d[1030][1030];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m,i,j,res,c=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> vn[i];
    for(int i=1;i<=m;i++)
        cin >> vm[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vn[i]==vm[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    }
    cout << d[n][m] << '\n';
    for(int i=0;i<c;i++)
        cout << vr[i] << " ";
    return 0;
}
