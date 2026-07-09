#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.in");

vector <int> a,b,s;
vector <vector <int> > x;

void read()
{
    int n,m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    x.resize(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int j=0; j<m; j++)
    {
        x[j].resize(m);
        cin >> b[j];
    }
}

void write()
{
    cout << s.size() << '\n';
    for (int i=s.size()-1; i>=0; i--)
        cout << s[i] << ' ';
}

void solve()
{
    for (int i=0; i<a.size(); i++)
        for (int j=0; j<b.size(); j++)
            if (a[i]==b[j])
                x[i][j]=1+x[i-1][j-1];
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
    for (int i=a.size()-1,j=b.size()-1; i>=0; )
        if (a[i]==b[j])
            s.push_back(a[i]),--i,--j;
        else
            if (x[i-1][j]<x[i][j-1]) --j; else --i;
}

main()
{
    read();
    solve();
    write();
}
