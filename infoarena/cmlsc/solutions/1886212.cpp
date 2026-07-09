#include <iostream>
#include <fstream>
using namespace std;
int a[1025],b[1025],c[1025][1025],n,m,st[1025];
void citire()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(int i=1; i<=n; i++)
    {
        f>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        f>>b[i];
    }
}
int maxim(int x,int y)
{
    if(x>y)
        return x;
    else return y;
}
void program()
{

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
            {
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
            }

}
void afisare()
{
    ofstream g("cmlsc.out");
    int max=c[n][m]+1,ii=0;
    g<<c[n][m]<<endl;
    for(int i=n; i>0; i--)
        for(int j=m; j>0; j--)
        {
            if(max>c[i][j] && a[i]==b[j])
            {
                st[ii]=a[i];
                ii++;
                max=c[i][j];
            }
        }
        for(int i=ii-1;i>=0;i--)
            g<<st[i]<<" ";
}
int main()
{
    citire();
    program();
    afisare();
    return 0;
}
