#include <fstream>
#include <iostream>
#include <stack>
using namespace std ;
ifstream f ("cmlsc.in") ;
ofstream g ("cmlsc.out");
int n,m,mx,a[1025],b[1025];
int matr[1025][1025];
stack<int> v;
void recursiv(int x,int y,bool oprit)
{
    int mx = max(matr[x-1][y],matr[x][y-1]);
    if(oprit)
        return;
    if(mx == 0)
    {
        oprit = true;
    }
    if(a[x] ==  b[y])
    {
        v.push(a[x]);
        recursiv(x-1,y-1,oprit);
    }
    else
    {
        if(matr[x-1][y] == mx)
            recursiv(x-1,y,oprit);
        else
            if(matr[x][y-1] == mx)
            recursiv(x,y-1,oprit);
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        f >> a[i];
    }
    for(int i = 1;i<=m;i++)
    {
        f >> b[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(a[i]== b[j])
            {
                matr[i][j] = 1 + matr[i-1][j-1];
            }
            else
                matr[i][j] = max(matr[i-1][j],matr[i][j-1]);
        }

    }
    g << matr[n][m]<< endl;
    recursiv(n,m,0);
    while(!v.empty())
    {
        g << v.top()<< " ";
        v.pop();
    }
    return 0 ;
}
