#include<iostream>
#include<fstream>
using namespace std;

int n,m,a[1030],b[1030],d[1030][1030],sir[1030],lsir=0;

void citire(){
    ifstream f("cmlsc.in");
    f>>n>>m; int i;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    f.close();
}
void rezolvare(){
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=n; j=m;
    while(i){
        if(a[i]==b[j]){
            sir[++lsir]=a[i];
            i--; j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    ofstream o("cmlsc.out");
    o<<lsir<<"\n";
    for(i=lsir;i>=1;i--)
        o<<sir[i]<<" ";
    o.close();
}
int main(){
    citire();
    rezolvare();
}
