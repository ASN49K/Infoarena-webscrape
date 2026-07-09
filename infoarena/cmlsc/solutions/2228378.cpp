#include <iostream>
#include <bits/stdc++.h>
#define NN 1024
using namespace std;
int n,m;
int imax;
int vn[NN],vm[NN];
int a[NN];
int pred[NN];
int mmaxa[NN];
int inversator[NN];
int lll[NN][NN];
vector <int> vv[NN];

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
int s=0;
int nnn=0;
int mmm=0;
for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++){
        if (vn[i]==vm[j]){
            lll[i][j]=lll[i-1][j-1]+1;
            if ((i>nnn)&&(j>mmm)){a[s]=vn[i];
            s++;
            nnn=i;
            mmm=j;}

        }
        else{
            lll[i][j]=max(lll[i-1][j], lll[i][j-1]);
        }
    }
}


        g << lll[n][m]<< endl;
for (int j=0; j<s; j++)
{
    g<<a[j]<<' ';
}
}
















