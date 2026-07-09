#include <fstream.h>
#include <iostream.h>
#include "lib.h"

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;

int main() {
	int lp=1, vlp=1;
	fin>>m>>n;
	int c[m+n+1];
	memset(c,0,sizeof(c));
	int a[m+1], b[n+1];
	for(int i=1;i<=m;i++) 
		fin>>a[i];
	for(int i=1;i<=n;i++)
		fin>>b[i];
	for(int i=1;i<=m;i++) {
		for(int j=lp;j<=n;j++) {
			if(a[i] == b[j]) {
				c[vlp]=a[i];
				vlp++;
				lp++;
				j=n+1; //ca sa iasa din for j
			}
		}
	}
	fout<<lp-1<<'\n';
	for(int i=1;i<lp;i++)
		fout<<c[i]<<" ";
}
