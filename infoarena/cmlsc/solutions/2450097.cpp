#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int NMAX=1025;
int x[NMAX],y[NMAX],c[NMAX][NMAX],n,m;
#define pb push_back
vector <int>sol;
int main()
{
    in>>n>>m;
    FOR(i,1,n)
        in>>x[i];
    FOR(j,1,m)
        in>>y[j];
    FOR(i,1,n)
    FOR(j,1,m){
        if(x[i]==y[j])
            c[i][j]=c[i-1][j-1]+1;
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    int i=n,j=m;
    out<<c[i][j]<<'\n';
    while(c[i][j]>=1){
        if(x[i]==y[j]) sol.pb(x[i]),i--,j--;
        else if(c[i-1][j]>c[i][j-1]) i--;
        else j--;
    }
    for(int i=c[n][m]-1;i>=0;i--)
        out<<sol[i]<<" ";
    return 0;
}
