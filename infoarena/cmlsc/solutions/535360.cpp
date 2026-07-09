#include<fstream>

using namespace std;
#define NM 1024
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[NM], b[NM], r[NM], n, m, x[NM][NM];

int main(){
	int i,j,k=0;
	in>>n>>m;
	for(i=0;i<n;++i)
		in>>a[i];
	for(j=0;j<m;++j)
		in>>b[j];
	if(a[0]==b[0])
		x[0][0]=1;
	for(j=1;j<m;++j)
		if(a[0]==b[j])
			x[0][j]=1;
	for(i=1;i<n;++i)
		if(a[i]==b[0])
			x[i][0]=1;
	for(i=1;i<n;++i)
		for(j=1;j<m;++j)
			if(a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else
				if(x[i][j-1]>=x[i-1][j])
					x[i][j]=x[i][j-1];
				else
					x[i][j]=x[i-1][j];
	out<<x[n-1][m-1]<<"\n";
	i=n-1; j=m-1;
	while(i>=0&&j>=0){
		if(a[i]==b[j]){
			r[k++]=a[i];
			i--;j--;
		}
		else
			if(x[i][j-1]>=x[i-1][j])
				j--;
			else
				i--;
	}
	for(k=x[n-1][m-1]-1;k>=0;k--)
		out<<r[k]<<" ";
	return 0;
}
