///#include <bits/stdc++.h>
#include <fstream>
using namespace std;ofstream cout("euclid2.out");ifstream cin("euclid2.in");
int a,b,n,f[100002];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a>b){int r=a;a=b;b=r;}
        while(a){
            int r=b%a;
            b=a;a=r;
        }
        f[i]=b;
    }
    for(int i=1;i<=n;i++)cout<<f[i]<<'\n';cout.close();
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

