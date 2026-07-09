#include<fstream>
using namespace std;
int m,n,j,i,k(0),a[1024][1024],v[1024],b[1024],s[1024]; 
int main()
{
ifstream fin("cmlsc.in");
fin>>n>>m;
for(i=1;i<=n;i++)
fin>>v[i];
for(j=1;j<=m;j++)
fin>>b[j];
fin.close();

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(v[i]==b[j])
a[i][j]=1+a[i-1][j-1];
else 
if(a[i][j-1]>a[i-1][j])
a[i][j]=a[i][j-1];
else 
a[i][j]=a[i-1][j];  

for(i=n , j=m;i;)
if(v[i]==b[j]){s[++k]=v[i];j--;i--;}
else if(a[i-1][j]<a[i][j-1])j--;
else i--;

    ofstream fout("cmlsc.out");
    fout<<k<<"\n";
    for(i=k;i;i--)
    fout<<s[i]<<" ";
    fout.close();
    return 0;
}
