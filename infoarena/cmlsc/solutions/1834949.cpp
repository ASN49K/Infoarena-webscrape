#include <vector>
#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

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
        x[i].resize(m);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];
}

void solve()
{
    for (int i=0; i<b.size(); i++)
        (a[0]==b[i])? x[0][i]=1 : x[0][i]=0;
    for (int i=0; i<a.size(); i++)
        (a[i]==b[0])? x[i][0]=1 : x[i][0]=0;
    for (int i=1; i<a.size(); i++)
        for (int j=1; j<b.size(); j++)
        {
            if (a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    for (int i=a.size()-1,j=b.size()-1; i>=0 && j>=0;)
        if (a[i]==b[j]) s.push_back(a[i]),i--,j--;
        else
            if (i==0) j--; else if (j==0) i--; else if (x[i-1][j]<x[i][j-1]) j--; else i--;
}

void write()
{
    cout << s.size() << '\n';
    for (int i=s.size()-1; i>=0; i--)
        cout << s[i] << ' ';
}

main()
{
    read();
    solve();
    write();
}
