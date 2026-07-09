#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int s[1025][1025],v[1025],u[1025],m,n;
void recursiv (int i,int j)
{
    if(i>=1&&j>=1)
    {
        if(v[i]==u[j])
        {
            recursiv(i-1,j-1);
            g<<v[i]<<" ";
        }
        else
        {
            if(s[i-1][j]>s[i][j-1])
                recursiv(i-1,j);
            else
                recursiv(i,j-1);
        }
    }
}
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>v[i];
    for(int j=1;j<=n;j++)
        f>>u[j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
           {
            if(v[i]==u[j])
            s[i][j]++;
            else
            {
                if(s[i-1][j]>s[i][j-1])
                    s[i][j]=s[i-1][j];
                else
                    s[i][j]=s[i][j-1];
            }
           }
    }
  g<<s[m][n]<<endl;
 recursiv(m,n);
    f.close();
    g.close();
    return 0;
}
