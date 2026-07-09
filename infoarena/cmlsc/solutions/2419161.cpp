#include<fstream>

using namespace std;

#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)


ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int cmmdc(int a, int b){
int c;
while(a%b!=0){
c=a%b;
a=b;
b=c;
}
return b;
}

short int a[1030],b[1030],mat[1030][1030],l[1300];
int m,n;

int doo(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i]==b[j])
				mat[i][j]=1+mat[i-1][j-1];
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
	return mat[n][m];
}


void recomp(int s){
	int x=n,y=m,t=1;
	while(s){
		if(a[x]==b[y]){
			l[t]=a[x];
			++t;
			--x;
			--y;
			--s;
		}
		else
			if(mat[x][y]==mat[x-1][y])
				--x;
			else
				--y;
	}
	--t;
	while(t>0){
		fout<<l[t]<<" ";
		--t;
	}
}

int main(){
int t,i;
fin>>n>>m;
for(i=1;i<=n;++i)
	fin>>a[i];
for(i=1;i<=m;++i)
	fin>>b[i];
t=doo();
fout<<t<<"\n";
recomp(t);
return 0;
}