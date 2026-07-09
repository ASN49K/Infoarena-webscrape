#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025],b[1025],v[1025][1025],s[1025][1025],m,n;

void scriere(int i,int j)
{
    if(i!=0&&j!=0)
    {
        if(s[i][j]==1)
        {
            scriere(i-1,j-1);
            cout<<a[i]<<' ';
        }
        else if(s[i][j]==2)
            scriere(i-1,j);
        else if(s[i][j]==3)
            scriere(i,j-1);


    }
}

int main()
{
    cin>>n>>m;
    int i,j;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1; i<=m; i++)
        cin>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                v[i][j]=v[i-1][j-1]+1;
                s[i][j]=1;
            }
            else

            {
                if(v[i-1][j]>v[i][j-1])
                {
                    s[i][j]=2;
                    v[i][j]=v[i-1][j];
                }
                else
                {
                    s[i][j]=3;
                    v[i][j]=v[i][j-1];
                }
            }
        }
    cout<<v[n][m]<<'\n';
    scriere(n,m);
    return 0;
}
