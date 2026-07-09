#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1030],b[1030],dd[1030][1030],sub[1030];
int main(){
	
long long int m,n;
in >>m>>n;

for(int i=1;i<=m;i++)
	in >>a[i];

for(int i=1;i<=n;i++)
	in >>b[i];


for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
	if(a[i] == b[j])
		dd[i][j]=dd[i-1][j-1]+1;
	else
		dd[i][j]=max(dd[i-1][j],dd[i][j-1]);
	
}
}
out <<dd[m][n]<<"\n";
int ii=0;
for(int i=m,j=n;i>=1 and j>=1;){
	if(a[i]==b[j])
		sub[++ii]=a[i],j--,i--;
	else if(dd[i-1][j]<dd[i][j-1])
		j--;
	else {
		i--;
	}
}
for(int i=ii;i>=1;i--){
	out <<sub[i]<<" ";
}
return 0;
}

