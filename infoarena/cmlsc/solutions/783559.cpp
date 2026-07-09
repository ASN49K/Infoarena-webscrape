#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],din[1026][1026],n,m,i,j;
in>>n>>m;
for(i=1;i<=n;i++) in>>a[i];
for(j=1;j<=m;j++) in>>b[j];

for(i=0;i<=n;i++) din[i][0]=0;
for(j=0;j<=m;j++) din[0][j]=0;

for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j]) din[i][j]=1+din[i-1][j-1];
	           else din[i][j]=max(din[i-1][j],din[i][j-1]);
int ll=n,cc=m,s[1025];
j=0;
while(ll && cc)
 {
    if(ll && cc && a[ll]==b[cc]) {  s[j]=a[ll]; j++; ll--; cc--; }
	
	if(ll && din[ll-1][cc]==din[ll][cc]) ll--;
  
	if(cc && din[ll][cc]==din[ll][cc-1]) cc--;
 }

out<<din[n][m]<<endl;
for(i=j-1;i>=0;i--)
	out<<s[i]<<" ";
return 0;
}