#include<cstdio>
int a,b,d,n,x,y;
void cmmdc (int a,int b){
	if(b==0)
		d=a;
	else
		cmmdc(b,a%b);
}
int main (){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		cmmdc(x,y);
		printf("%d\n",d);
	}
	return 0;
 }