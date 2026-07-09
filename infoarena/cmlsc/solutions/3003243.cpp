#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
short int x[1025];
short int y[1025];
short int a[1025][1025];
short int f[1025];
vector <short int> b;
int main()
{
    short int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int j=0;j<m;j++)
        cin >> y[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i-1]==y[j-1])
            {
                a[i][j]=1+a[i-1][j-1];
                if(!f[i-1])
                    b.push_back(x[i-1]),f[i-1]=1;
            }
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
    cout << a[n][m] << '\n';
    for(int i=0;i<b.size();i++)
        cout << b[i] << ' ';
    return 0;
}
