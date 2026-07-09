#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int a[1050],b[1050];
int d[1050][1050];
int n,m;

void subsir(int i, int j){
    if(i==0||j==0)
        return;
    if(a[i]==b[j]){
        subsir(i-1,j-1);
        g<<a[i]<<" ";
        return;
    }
    if(d[i-1][j]>d[j][j-1])
        subsir(i-1,j);
    else
        subsir(i,j-1);
}

int nr[1005];

int main()
{

    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    for(int i=1;i<=m;i++){
        f>>b[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            g<<d[i][j]<<" ";
        g<<'\n';

    }
    //subsir(pm);
}
