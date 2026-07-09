#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],x[1025][1025],y[1025];

void read(){
f>>a[0]>>b[0];
for(int i=1;i<=a[0];i++) f>>a[i];
for(int i=1;i<=b[0];i++) f>>b[i];
}

void solve(){
x[1][0]=x[0][1]=0;
for(int i=1;i<=a[0];i++)
for(int j=1;j<=b[0];j++)
if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
else x[i][j]=max(x[i-1][j],x[i][j-1]);
int i,j;
i=a[0];
j=b[0];
y[0]=0;
while(i>0&&j>0){
if(i>0) while(x[i][j]==x[i-1][j]) i--;
if(j>0) while(x[i][j]==x[i][j-1]) j--;
y[++y[0]]=a[i];
i--;
j--;
}
g<<x[a[0]][b[0]]<<"\n";
for(i=y[0];i>=1;i--) g<<y[i]<<" ";
}

int main(){
read();
solve();
return 0;
}
