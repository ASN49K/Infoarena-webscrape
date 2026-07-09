#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,i,a[1025][1025],j,m,x[1025],y[1025];
void afis(int i, int j)
{if(i==1&&j==1)if(x[i]=y[j])g <<x[i]<<" ";
    if(i>1||j>1)
    {
        if(x[i]==y[j]){afis(i-1,j-1);g<<x[i]<<" ";}
        else if(a[i][j-1]<a[i-1][j])afis(i-1,j);
        else afis(i,j-1);
    }


}

int main()
{f >>n;
f >>m;
for(i=1;i<=n;i++)
    f >>x[i];
for(i=1;i<=m;i++)
    f >>y[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
{
    if(x[i]==y[j])a[i][j]=a[i-1][j-1]+1;
    else
    {int mx;
    mx=a[i][j-1];
    if(a[i-1][j]>mx)mx=a[i-1][j];
    a[i][j]=mx;

    }
}
g <<a[n][m]<<endl;
afis(n,m);
    return 0;
}


