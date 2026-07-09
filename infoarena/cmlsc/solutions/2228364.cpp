#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int imax;
int vn[10000],vm[10000];
int a[10000];
int pred[10000];
int mmaxa[10000];
int inversator[10000];
int lll[10000][10000];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
f>>n>>m;

for (int i=1; i<=n; i++){
    f>>vn[i];
}
for (int i=1; i<=m; i++){
    f>>vm[i];
}
for (int i=1; i<=n; i++){
lll[i][0]=0;
}
for (int i=1; i<=m; i++){
lll[0][i]=0;
}

for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++){
        if (vn[i]==vm[j]){
            lll[i][j]=lll[i-1][j-1]+1;

        }
        else{
            lll[i][j]=max(lll[i-1][j], lll[i][j-1]);
        }
    }
}


        g << lll[n-1][m-1]<< endl;

}
















