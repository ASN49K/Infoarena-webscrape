#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025][1025],x[1025],y[1025],sir[1025],c;
int main()
{   int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>x[i];
    for(i=1;i<=m;i++)fin>>y[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
            if(x[i]==y[j])a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    for(i=n,j=m;i,j;){
        if(x[i]==y[j]){sir[++c]=x[i];i--;j--;}
        else if(a[i-1][j]>a[i][j-1])i--;else j--;

    }
    fout<<c<<"\n";
    for(i=c;i>0;i--)fout<<sir[i]<<" ";
    return 0;
}
