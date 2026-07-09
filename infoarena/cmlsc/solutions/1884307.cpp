#include <iostream>
#include <fstream>

using namespace std;

int m,n,a[1026][1026];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire()
{
 f>>m>>n;
 int i;
 for(i=2;i<=m+1;i++)
        f>>a[0][i];
 for(i=2;i<=n+1;i++)
    f>>a[i][0];
}


void pd()
{
    int i,j;
    for(i=2;i<=n+1;i++)
        for(j=2;j<=m+1;j++)
    {
        if(a[i][0]==a[0][j])
            a[i][j]=a[i-1][j-1]+1;
        else
        {
            if(a[i-1][j]>=a[i][j-1])
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i][j-1];
        }
    }
    g<<a[n+1][m+1]<<endl;
}
void drum(int i,int j)
{
    if(a[i][j]>0)
    {
        if(a[i][0]==a[0][j])
        {
            drum(i-1,j-1);
            g<<a[i][0]<<" ";
        }
        else if(a[i][j-1]==a[i][j])
            drum(i,j-1);
        else
            drum(i-1,j);
    }
}
int main()
{
    citire();
    pd();
    drum(n+1,m+1);

    return 0;
}
