#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int v[1024],v1[1024],bst,a[1024][1024], sir[1024],n,m;

int main(){


    in>>n>>m;
    for(int i=1 ; i <= n ;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>v1[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){

            if(v[i] == v1[j])
                a[i][j]= 1+a[i-1][j-1];
            else
                a[i][j]= max(a[i-1][j],a[i][j-1]);

        }

    for(int i=n,j=m;i>=1;){

        if(v[i]==v1[j])
            sir[++bst]=v[i], i--,j--;
        else if(a[i-1][j]<a[i][j-1])
                j--;
        else
            i--;
    }

    out<<bst<<'\n';
    for(int i=bst;i>=1;i--)
        out<<sir[i]<<" ";



    return 0;
}
