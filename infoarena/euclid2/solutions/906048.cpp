#include<iostream>
#include<cstdio>
using namespace std;
int n;
int euclid (int a,int b){
	if(b==0)
		return a;
	else
		return euclid (b,a%b);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}
