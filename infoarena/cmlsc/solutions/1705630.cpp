#include <fstream>
#include <vector>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m;
vector <int> x,y;
vector < vector<int> > a,b,c;
void init(vector < vector<int> > &a)
{
    a.resize(n+1);
    for (int i=0;i<=n;i++)
    a[i].resize(m+1,0);
}
void kiir1(int i,int j)
{
    if (!i or !j)
        return;
    if (a[i-1][j]>a[i][j-1]) kiir1(i-1,j);
        else                 kiir1(i,j-1);
    if (x[i]==y[j])
        cout<<x[i]<<" ";
}
void kiir(int i,int j)
{
    if (!i && !j)
        return;
    kiir(b[i][j],c[i][j]);
    cout<<x[i]<<" ";
}
int main()
{
    cin>>n>>m;
    x.resize(n+1,0);
    y.resize(m+1,0);
    for (int i=1;i<=n;i++)
        cin>>x[i];
    for (int i=1;i<=m;i++)
        cin>>y[i];
    init(a);
    init(b);
    init(c);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        if (x[i]==y[j])
        {
            a[i][j]=1+a[i-1][j-1];
            b[i][j]=i-1;
            c[i][j]=j-1;
        }
        else
        if (a[i-1][j]>a[i][j-1])
        {
            a[i][j]=a[i-1][j];
            b[i][j]=b[i-1][j];
            c[i][j]=c[i-1][j];
        }
        else
        {
            a[i][j]=a[i][j-1];
            b[i][j]=b[i][j-1];
            b[i][j]=c[i][j-1];
        }
    }
    cout<<a[n][m]<<"\n";
    kiir1(n,m);
}
