#include <iostream>
#include <fstream>
using namespace std;
int a[100],b[100],c[100][100],n,m;
void citire()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(int i=1;i<=m;i++)
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

    for(int i=1;i<=n;i++)
{
        for(int j=1;j<=m;j++)
        {
        if(a[i]==b[j])
            c[i][j]=1+c[i-1][j-1];
            else
            {
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
            }
        }
    }
}
void afisare()
{
    ofstream g("cmlsc.out");
    int max=0;
    g<<c[n][m]<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(max<c[i][j])
                {
                    g<<a[i]<<" ";
                    max=c[i][j];
                }
}
int main()
{
    citire();
    program();
    afisare();
    return 0;
}
