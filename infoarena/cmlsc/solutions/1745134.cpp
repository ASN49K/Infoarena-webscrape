#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream f ("cmlsc.in");
ofstream t ("cmlsc.out");

int m,n;
vector <int> v1,v2,sol;

int max(const int x,const int y,const int z,const int i){
if (x>y and x>z){sol.push_back(v1[i]); return x;}
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
d[i][j]=max(d[i-1][j-1]+(v1[i-1]==v2[j-1]),d[i-1][j],d[i][j-1],i-1);
t<<d[m][n]<<'\n';
for (int i=0;i<d[m][n];++i)
t<<sol[i]<<" ";
}

int main()
{
    read();
    solve();
    return 0;
}
