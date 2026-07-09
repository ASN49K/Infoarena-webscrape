#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream f ("cmlsc.in");
ofstream t ("cmlsc.out");

int m,n;
vector <int> v1,v2,sol;

int max(const int x,const int y,const int z){
if (x>=y and x>=z) return x;
if (y>=x and y>=z) return y;
if (z>=x and z>=y) return z;
return -1;}

void read(){
f>>m>>n;
v1.resize(m);
v2.resize(n);
for (int i=0;i<m;++i)
f>>v1[i];
for (int i=0;i<n;++i)
f>>v2[i];
}

void solve(){
int d[m+1][n+1];
memset(d,0,sizeof(d));
for (int i=1;i<=m;++i)
for (int j=1;j<=n;++j)
d[i][j]=max(d[i-1][j-1]+(v1[i-1]==v2[j-1]),d[i-1][j],d[i][j-1]);
t<<d[m][n]<<'\n';
int i=m,j=n;
get_heritage:
    if(d[i][j] == 0) goto fin;
    if(v1[i-1]==v2[j-1])
    {
        sol.push_back(v1[i-1]);
        --i,--j;
        goto get_heritage;
    }
    else if(d[i][j] == d[i-1][j]){
        --i;
        goto get_heritage;}
    else{
        --j;
        goto get_heritage;}
   fin:for (int i=d[m][n]-1;i>=0;--i)
   t<<sol[i]<<" ";
}

int main()
{
    read();
    solve();
    return 0;
}
