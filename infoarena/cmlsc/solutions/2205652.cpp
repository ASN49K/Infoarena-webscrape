///;#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
#define for(i, a, b) for(int i = a; i <= b; i++)
using namespace std;ifstream cin("cmlsc.in");ofstream cout("cmlsc.out");
int maxi(int a,int b){
    return (a>b)? a : b;
}
int n,m,f[1025],l,v[1025],k[1025][1025],s[1025];
int main()
{
    cin>>n>>m;for(i ,1 ,n)cin>>f[i];for(i ,1 ,m)cin>>v[i];
    for(i ,1 ,n)
        for(j ,1 ,m){
            if(f[i]==v[j])
                k[i][j]=1+k[i-1][j-1];
            else {
                k[i][j]=maxi(k[i-1][j],k[i][j-1]);
            }
        }
    int i=n,j=m;
    while(i){
        if(f[i]==v[j]){
            s[++l]=f[i];i--;j--;
        }
        else if(k[i-1][j]<k[i][j-1])
            j--;
        else i--;
    }
    cout<<l<<'\n';
    for(i ,1 ,l)cout<<s[l-i+1]<<' ';cout.close();
}

///
/*

*/
























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

