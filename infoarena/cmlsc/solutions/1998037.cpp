#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],c[1025][1025];
void drum(int i,int j)
{
    if(i==0||j==0)
        return;
    if(a[j]==b[i])
    {
        drum(i-1,j-1);
        out<<a[j]<<" ";

    }
    else
    {
     if(c[i-1][j]<c[i][j-1])
     drum(i,j-1);
     else
     drum(i-1,j);
    }

}

int main()
{

    int n,m,i,j;
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(i=1; i<=m; i++)
        in>>b[i];


    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[j]==b[i])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    out<<c[m][n]<<endl;
    drum(m,n);

    return 0;
}
