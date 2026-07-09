#include<cstdio>
#include<fstream>
#include<iostream>

using namespace std;

int N;

fstream f,g;


int euclid(int n,int m){
	int r=0;
	do{
		r=n%m;
		n=m;
		m=r;
	}while(r>0);
	return n;
}


int main(){
	int i=12,j=42;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&N);
	for(;N--;){
		scanf("%d %d",&i,&j);
		printf("%d\n",euclid(i,j));
	}
	return 0;
}
