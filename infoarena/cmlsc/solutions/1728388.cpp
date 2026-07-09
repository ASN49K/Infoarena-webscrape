#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main(){

int a[1025],b[1025],n,m,x,k=0;

f>>n>>m;

for(int i=1;i<=n;i++)
    f>>a[i];

for(int i=1;i<=m;i++){
    f>>x;
    for(int j=1;j<=n;j++)
    if(a[j]==x){
        k++;
        b[k]=x;
    }
}

g<<k<<'\n';
for(int i=1;i<=k;i++)
    g<<b[i]<<" ";

return 0;
}
