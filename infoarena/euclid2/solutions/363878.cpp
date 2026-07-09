#include <cstdio>

using namespace std;

int cmmdc(int a,int b){
	if(b==0)return a;
	else return cmmdc(a%b,b);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,n;
	scanf("%u",&n);
	for(int i=0;i<n;i++){
		scanf("%u %u",&a,&b);
		printf("%u\n",cmmdc(a,b));
	}
}