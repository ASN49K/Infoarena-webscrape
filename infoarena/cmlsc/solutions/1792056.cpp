#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maxim(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}
int a[1024],b[1024],c[1024][1024],d[1024],nr;
int main()
{
    int i,j,n,m;

    f>>n>>m;
    for(i=1;i<=n;i++){
        f>>a[i];
    }
    for(j=1;j<=m;j++){
        f>>b[j];
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[i][j]= c[i-1][j-1]+1;
            }
            else{
                c[i][j] = maxim(c[i][j-1],c[i-1][j]);
            }
        }
    }
    i=n;
    j=m;
    while(i){
        if(a[i]==b[j]){
            d[++nr]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]<c[i][j-1]){
            j--;
        }
        else i--;
    }

    g<<nr<<endl;
    i=nr;
    while(i){
        g<<d[i]<<" ";
        i--;
    }
    return 0;
}
