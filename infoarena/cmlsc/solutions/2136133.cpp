#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int c[1025][1025],m,n;
char a[1025],b[1025];
void recursiv(int i,int j)
{
    if(c[i][j]!=0)
    {
        if(c[i][j]==c[i-1][j])
            recursiv(i-1,j);
        else if(c[i][j]==c[i][j-1])
            recursiv(i,j-1);
        if(c[i][j]>c[i-1][j] && c[i][j]>c[i][j-1])
        {
            recursiv(i-1,j-1);
            g<<a[j-1]<<" ";
        }
    }
}
int main()
{
    f>>n;
    f>>m;
    for(int i=0; i<n; i++)
    {
        f>>a[i];
    }
    for(int i=0; i<m; i++)
    {
        f>>b[i];
    }
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                c[i][j]=0;
            else
            {
                if(b[i-1]==a[j-1])
                    c[i][j]=1+c[i-1][j-1];
                else
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    g<<c[m][n]<<endl;
    recursiv(m,n);
    return 0;
}
