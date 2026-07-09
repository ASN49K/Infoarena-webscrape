#include<bits/stdc++.h>
using namespace std;
int n,m,a[1025],b[1025],q,d[1029][1029],c[1025],k=1;
int main(){
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    g<<d[n][m] << '\n';
    while(n >= 1 && m >= 1)
    {
        //g << n << " " << m << '\n';
        if(d[n][m] - 1 == d[n - 1][m - 1])
        {
            c[k]=a[n];
            k++;
            n--;
            m--;
        }
        else if(d[n - 1][m] >= d[n][m - 1])
            n--;
        else
            m--;
    }
    for(int i=k-1;i>=1;i--)
        g<<c[i]<<" ";
}