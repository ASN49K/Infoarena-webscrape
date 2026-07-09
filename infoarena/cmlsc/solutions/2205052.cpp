///#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
using namespace std;ofstream cout("cmlsc.out");ifstream cin("cmlsc.in");
int a[1025],b[1025],c[1025],n,m,l;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n);
    sort(b+1,b+m);
    int x=1,y=1;
    while(x<=n && y<=m){
        if(a[x]>b[y])y++;
        else if(a[x]<b[y])x++;
        else {l++;c[l]=a[x];x++;y++;}
    }
    while(x<=n){
        if(a[x]==b[y-1]){l++;c[l]=a[x];}
        x++;
    }
     while(y<=m){
        if(a[x-1]==b[y]){l++;c[l]=b[y];}
        y++;
    }

    cout<<l<<'\n';
    for(int i=1;i<=l;i++)cout<<c[i]<<' ';cout.close();
}

///

























///else for(int j=1;j<=n;j++)f[i][j]=f[n-i+1][j]=f[j][n-i+1]=f[j][i]=0;#include <fstream>
///#include <algorithm>
///cout.close();ifstream cin("arhitectura2.in");ofstream cout("arhitectura2.out");

/**
#include <fstream>
using namespace std;ifstream cin("forus.in");ofstream cout("forus.out");
int p,n,f[31];
int main()
{
    cin>>p;
    if(p==1){
        cin>>n;for(int i=1;i<=n;++i)cin>>f[i];
        int l=n,k=0;
        for(int i=1;i<=n;i++){
            while(f[i]){
                int c=f[i]%10;f[i]/=10;if(c==0)k=1;
            }
            l-=k;k=0;
        }
        cout<<l;
    }
    cout.close();
}
*/









///







///1817#include <fstream>
///ifstream cin("compus.in");ofstream cout("compus.out");
  ///cout.close();













































/// ////////////////////////////////////////////////////muie

