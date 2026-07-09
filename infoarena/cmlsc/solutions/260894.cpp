#include<fstream.h>    
int i,j,n,m,s,sl[1025],a[1025],b[1025],v[1025][1025];    
ifstream fin("cmlsc.in");    
ofstream fout("cmlsc.out");    
void citire(){    
fin>>n>>m;    
for(i=1;i<=n;i++)    
fin>>a[i];    
for(i=1;i<=m;i++)    
fin>>b[i];    
}    
int max(int a,int b){    
return (a>b)?a:b;    
}    
void din(){    
for(i=1;i<=n;i++)    
for(j=1;j<=m;j++)    
if(a[i]==b[j])    
v[i][j]=1+v[i-1][j-1];    
else    
v[i][j]=max(v[i-1][j],v[i][j-1]);    
i=n;    
j=m;    
while(i>0&&j>0)    
if(a[i]==b[j]){    
sl[++s]=a[i];    
i--;    
j--;    
}    
else    
if(v[i-1][j]>v[i][j-1])    
i--;    
else    
j--;    
fout<<v[n][m]<<'\n';    
for(i=s;i>=1;i--)    
fout<<sl[i]<<" ";    
}    
int main(){    
citire();    
din();    
return 0;       
}
