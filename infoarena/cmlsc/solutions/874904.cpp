#include<fstream>
#include<iostream>
#include<limits.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],c[1025][1025],n,m,v[1025];
void cit(){
    in>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
}
int main(){
    cit();
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                if(c[i-1][j]>=c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
    out<<c[n][m]<<'\n';
    int p=c[n][m];
    i=n,j=m;
    while(i>0&&j>0){
        if(a[i]==b[j]){
            v[p--]=a[i--];
            j--;
        }
        else
            if(c[i-1][j]>=c[i][j-1])
                i--;
            else
                j--;
    }
    for(i=1;i<=c[n][m];i++)
        out<<v[i]<<' ';
    return 0;
}
