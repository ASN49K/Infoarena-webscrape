#include <cstdio>
using namespace std;
inline int cmmdc(int a,int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d %d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
	fclose(stdin),fclose(stdout);
    return 0;
}
