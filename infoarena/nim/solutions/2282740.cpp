#include<stdio.h>

#include<iostream>
#include<fstream>

using namespace std;

#define MAXN 10000
int V[MAXN];

int n;

int main(){
	int t;

	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	scanf("%d", &t);
	int sum;

	for(int i=0;i<t;i++){
		scanf("%d", &n);
		sum=0;
		for(int j=0;j<n;j++){
			scanf("%d", &V[i]);
			sum^=V[i];
		}
		if(sum==0)
			printf("NU\n");
		else
			printf("DA\n");
	}
	
	return 0;
}