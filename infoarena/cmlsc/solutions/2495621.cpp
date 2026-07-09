#include <bits/stdc++.h>

using namespace std;
int x[1050],y[1050],n,m;
int a[1050][1050];
int maax=0;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void afis(int i,int j){
    if(i*j!=0){
        if(x[i]==y[j]){
            afis(i-1,j-1);
            g<<x[i]<<" ";
        }
        else if(a[i-1][j]>a[i][j-1])afis(i-1,j);
        else afis(i,j-1);

    }
}

int main()
{f>>n>>m;
for(int i=1;i<=n;i++){
        f>>x[i];
}
for(int i=1;i<=m;i++){
    f>>y[i];
}
for(int i=1;i<=m;i++){
    if(x[1]==y[i]){
        a[1][i]=1;
    }
    else a[1][i]=a[1][i-1];
}
for(int i=2;i<=n;i++){
    if(x[i]==y[1]){
        a[i][1]=1;
    }
    else a[i][1]=a[i-1][1];
}
for(int i=2;i<=n;i++){
    for(int j=2;j<=m;j++){
        if(x[i]==y[j]){
            a[i][j]=a[i-1][j-1]+1;
        }
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
}
    g <<a[n][m]<< endl;
    afis(n,m);
    return 0;
}
