#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
#define NMAX 1024
int a[NMAX][NMAX];
int x[NMAX];
int y[NMAX];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int j=0;j<m;j++)
        cin >> y[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i-1]==y[j-1])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    cout << a[n][m] << '\n';
    int i=n;
    int j=m;
    vector<int> sol;
    while(a[i][j])
    {
        if(x[i-1]==y[j-1])
        {
            sol.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(int i=sol.size()-1;i>=0;i--)
        cout << sol[i] << ' ';
    return 0;
}
