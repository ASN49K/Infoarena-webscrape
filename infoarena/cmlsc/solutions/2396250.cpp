//#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

vector<int>meg;

int x[1001],y[1001],a[1001][1001],i,j,n,m;
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;++i)
        cin>>x[i];
    for(i=1;i<=n;++i)
        cin>>y[i];

    for(i=0;i<=m;++i)
    {
        for(j=0;j<=n;++j)
        {
            if(j==0 || i==0) a[i][j]=0;
            else
            {
                if(x[i]==y[j])
                {
                        a[i][j]=1+a[i-1][j-1];
                        meg.push_back(y[j]);
                }
                if(x[i]!=y[j]) a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }

    }

   cout<<a[m][n]<<"\n";
    for(i=0;i<meg.size();++i)
        cout<<meg[i]<<" ";
    return 0;
}
