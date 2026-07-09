#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define ar array
#define ln '\n'
#define cin f
#define cout g
#define pb push_back
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],mat[1025][1025],k,sir[1025];
int main(){
    cin>>n>>m;
    loop(i,1,n)cin>>a[i];
    loop(i,1,m)cin>>b[i];
    loop(i,1,n)
    loop(j,1,m)
    if(a[i]==b[j])mat[i][j]=mat[i-1][j-1]+1;
    else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    for(int i=n,j=m;i;){
        if(a[i]==b[j])sir[++k]=a[i],i--,j--;
        else if(mat[i-1][j]<mat[i][j-1])j--;
        else i--;
    }
    cout<<k<<ln;
    for(int i=k;i>=1;i--)cout<<sir[i]<<' ';
}
/**
1 2 4 6 7
1 3 2 5 7
1 2 0 0 3

*/
