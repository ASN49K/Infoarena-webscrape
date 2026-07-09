#include<stdio.h>

#include<iostream>
#include<fstream>

using namespace std;

int n;

int main(){
	int t;

	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	scanf("%d", &t);
	int sum,val;

	for(int i=0;i<t;i++){
		scanf("%d", &n);
		sum=0;
		for(int j=0;j<n;j++){
			scanf("%d", &val);
			sum^=val;
		}
		if(sum==0)
			printf("NU\n");
		else
			printf("DA\n");
	}
	
	return 0;
}