#include <iostream>
#include <stdio.h>
using namespace std;
int max(short a,short b){
	return a>b?a:b;	
}

int d[1050][1050],res[1050],resc;


int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	short x,y;
	
	int b[1050],a[1050];
	scanf("%d %d", &x,&y);
	
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i]);
	}	
	for(int i=1;i<=y;i++){
		scanf("%d",&b[i]);
	}
	
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(a[i]==b[j])d[i][j]=1+d[i-1][j-1];
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}	
	cout<<d[x][y]<<endl;
	
	for(int i=x,j=y;i>0,j>0;){
			if(a[i]==b[j])res[resc++]=a[i],i--,j--;
			else if(d[i-1][j]<d[i][j-1])j--;
			else i--;
	}
	for(int i=resc-1;i>=0;i--){
		cout<<res[i]<<" ";
	}
}
