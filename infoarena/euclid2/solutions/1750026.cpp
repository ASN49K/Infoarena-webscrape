#include <iostream>
#include <stdio.h>
int euclid(int a,int b){
	if(b==0)return a;
	euclid(b,a%b);
}
int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int x,y,t;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d %d", &x,&y);
		printf("%d\n",euclid(x,x%y));
	}
}

