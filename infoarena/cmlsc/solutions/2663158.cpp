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
    res=d[n][m];
    cout << d[n][m] << '\n';
    i=n;
    j=m;
    while(d[i][j]>0)
    {
        if(d[i][j]>d[i-1][j] && d[i][j]>d[i][j-1])
        {
            vr[c]=vn[i];
            c++;
            i--;
            j--;
        }
        else
        {
            if(d[i][j]==d[i-1][j])
                i--;
            else
                j--;
        }
    }
    for(int i=c-1;i>=0;i--)
        cout << vr[i] << " ";
    return 0;
}
