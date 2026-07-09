#include <cstdio>
#define NM 1030

using namespace std;

inline int max(int a,int b) {return(a<b?b:a);}
int N,M,i,j,A[NM],B[NM],D[NM][NM],ANS[NM],ans=0;

int main() {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d",&N);scanf("%d",&M);
	for (i=1;i<=N;i++) scanf("%d",&A[i]);
	for (j=1;j<=M;j++) scanf("%d",&B[j]);
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			if (A[i]==B[j]) D[i][j]=1+D[i-1][j-1];
				else D[i][j]=max(D[i-1][j],D[i][j-1]);
	for (i=N,j=M;i!=0 && j!=0;) {
		if (A[i]==B[j]) {ANS[++ans]=A[i];i--;j--;continue;}
		if (D[i-1][j]>D[i][j-1]) --i;
		                   else --j;
	}
	printf("%d\n",ans);
	for (i=1;i<=ans;i++) printf("%d ",ANS[ans-i+1]);
	printf("\n");
	return 0;
}
