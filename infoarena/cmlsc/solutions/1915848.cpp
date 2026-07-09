#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,a[1025],b[1025],d[1025][1025];
stack <int> s;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    fout<<d[n][m]<<'\n';
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j]){s.push(a[i]);i--;j--;}
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    while(!s.empty())
    {
        fout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
