#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
int a[1055],b[1055];
int v[1055][1055];
vector<int>st;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    g<<v[n][m]<<'\n';
    int i=n,j=m;
    while(v[i][j])
    {
        if(a[i]==b[j])
        {
            st.push_back(a[i]);
            i--;j--;
        }
        else
        {
            if(v[i-1][j]>=v[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i=st.size()-1;i>=0;i--)
        g<<st[i]<<" ";
    return 0;
}
