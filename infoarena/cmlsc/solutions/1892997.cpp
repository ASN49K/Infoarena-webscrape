#include<fstream>
#include<stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,a[1025],b[1025],d[1025][1025],j;
stack <int >q;
int main()
{
fin>>n>>m;
for(i=1;i<=n;i++)
    fin>>a[i];
for(i=1;i<=m;i++)
    fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
    {
        d[i][j]=1+d[i-1][j-1];
    }
    else
        d[i][j]=max(d[i-1][j],d[i][j-1]);
i=n;j=m;
while(i&&j)
{
    if(a[i]==b[j]){q.push(i);i--;j--;}
    else
        if(d[i-1][j]>d[i][j-1])
        i--;
    else
        j--;
}
fout<<d[n][m]<<'\n';
while(!q.empty())
{
    fout<<a[q.top()]<<' ';
    q.pop();
}

}
