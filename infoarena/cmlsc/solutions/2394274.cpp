#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int i,j,n,m,e[1025],f[1025],x[1025][1025],k;
vector <int> t;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>e[i];

    for(i=1;i<=m;++i)
        cin>>f[i];


    for(i=0;i<=n;++i)
        for(j=0;j<=m;++j)
        {
            if(e[i]==f[j]) x[i][j]=1+x[i-1][j-1];
            else if(i==0 || j==0) x[i][j]=0;
            else if(e[i]!=f[j]) x[i][j]=max(x[i-1][j],x[i][j-1]);
        }

    cout<<x[n][m]<<"\n";

    i=n;
    j=m;
    while(x[i][j]!=0)
    {
        if(x[i][j]==x[i-1][j]) i--;
        else if(x[i][j]==x[i][j-1]) j--;
        else if(x[i][j]==x[i-1][j-1]+1)
        {
            t.push_back(e[i]);
            i--;
            j--;
        }
    }

    k=t.size();

    for(i=k-1;i>=0;--i)
        cout<<t[i]<<" ";
 return 0;
}
