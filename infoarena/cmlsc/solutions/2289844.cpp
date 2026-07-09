#include<cstdio>

const int MAX = 1025;
int n,m,A[MAX],B[MAX],memo[MAX][MAX];

int max(int x,int y){
	if(x>y) return x;
	return y;
}

void dynamic(){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(A[i]==B[j]) memo[i][j]=memo[i-1][j-1]+1;
			else memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
		}
	}
//	printf("%d\n",memo[n][m]);
}

void build(){
	int solution[MAX];
	int i,j,counter;
	i=m;
	j=n;
	counter=0;
	while(i){
		if(A[i]==B[j]){
			solution[++counter]=A[i];
			--i;--j;
		}else	if(memo[i-1][j]<memo[i][j-1]) j--;
				else i--;	
	}
	printf("%d\n",counter);
	for(int i=counter;i;--i) printf("%d ",solution[i]);
	//for(i=0;i<memo[n][m];++i) printf("%d ",solution[i]);
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;++i) scanf("%d",&A[i]);
	for(int i=1;i<=n;++i) scanf("%d",&B[i]);
//	printf("%d\nasd",memo[n][m]);
	dynamic();	
	build();
	
}
