#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int mat[1025][1025],n,m,a[1025],b[1025],t[1025],c;
void citire()
{
    in>>n;
     in>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
        for(int j=1;j<=m;j++)
            in>>b[j];

}
void sol()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j])
        mat[i][j]=1+mat[i-1][j-1];
        else
        mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

}
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
void traseu(int i,int j)
{
    while(mat[i][j])
    {
       if(a[i]==b[j])
       {
            t[c++]=a[i];
            i--; j--;
       }
       else
        if(mat[i][j-1]==mat[i][j])
        j--;
       else
        i--;
    }
}
int main()
{
    citire();
    sol();
    out<<mat[n][m]<<"\n";
    traseu(n,m);
    for(int i=c-1;i>=0;i--)
        out<<t[i]<<" ";
    return 0;
}
