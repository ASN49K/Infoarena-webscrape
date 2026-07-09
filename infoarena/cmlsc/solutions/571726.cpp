#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int n, m,bst, i, j;
int a[1024], b[1024], t[1024][1024];
int ered[1024];

int megnez(int a, int b){
	return (a>b)?a:b;
}

void beolvas(){
	ifstream be ("cmlsc.in" , ifstream::in );
	be>>n;
	be>>m;
	for (int i=1;i<=n;i++)
		be>>a[i];
	for (int i=1;i<=m;i++)
		be>>b[i];
	be.close();
}

void kiir(){
	ofstream ki("cmlsc.out");
	ki<<bst<<"\n";
	for (int i=bst;i;i--)
		ki<<ered[i]<<" ";
	ki.close();
}

int main(){
	beolvas();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				t[i][j]=t[i-1][j-1]+1;
			else t[i][j]=megnez(t[i-1][j], t[i][j-1]);
		}
	for(i=n,j=m;i;){
		if(a[i]==b[j]){
			ered[++bst]=a[i];
			i--;
			j--;
		}
		else {
			if(t[i-1][j]<t[i][j-1])
				j--;
			else i--;
		}
	}
	kiir();
	return 0;
}