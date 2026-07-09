#include<iostream>
#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int x[1100],y[1100],a[1100][1100],m,n,k;
void citire()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)f>>x[i];
    for(i=1;i<=m;i++)f>>y[i];
    f.close();
}
int maxim(int x,int y)
{
    if(x>y)return x;
    return y;
}
void dinamic()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j])a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
    //cout<<"Lungimea maxima este "<<a[n][m]<<endl;
    o << a[n][m] << '\n';
}
void afisaredr () {
    int i,j;
    k=a[n][m];
    for (i=n;i>=1 && k>0;i--) {
        for (j=m;j>=1 && k>0;j--) {
            if (x[i]==y[j]){k--; o<<x[i]<<' ';}
        }
    }
}
/*void afis (int i, int j, int k) {
    if (k>0) {
        if (i>=1)
            if (j>=1) {
                if (x[i]==y[j]) {
                    //cout<<x[i]<<' ';
                    afis (i, j-1, k-1);
                }
                else afis (i,j-1,k);
            }
        else afis (i-1,m,k);
    }
}*/
int main()
{
    citire();
    dinamic();
    afisaredr();
    //afis(n,m,a[n][m]);
    return 0;
}
