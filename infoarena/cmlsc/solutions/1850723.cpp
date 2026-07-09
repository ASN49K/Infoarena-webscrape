#include<fstream>
#include<stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX=1035;
int mat[NMAX][NMAX],a[NMAX],b[NMAX],n,m;
stack<int>s;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int i=1;i<=m;++i)
        fin>>b[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    fout<<mat[n][m]<<'\n';
    int i=n,j=m;
    while(i>=1)
        if(a[i]==b[j])
        {
            s.push(a[i]);
            --i;
            --j;
        }
        else if(mat[i-1][j]<mat[i][j-1])
            --j;
        else
            --i;
    while(s.empty()==false)
    {
        fout<<s.top()<<' ';
        s.pop();
    }
}
