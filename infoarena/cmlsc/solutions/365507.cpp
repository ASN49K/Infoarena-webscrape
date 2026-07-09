/*
 	Se dau doua siruri. sa se determine cel mai lung subsir comun
 */
#include <fstream>
#include <iostream>
using namespace std;
#define  MAX 1025
int a[MAX][MAX], v[MAX], u[MAX], m, n;

void read();
void dinamica();
void write();

void read(){
	ifstream fin("cmlsc.in");
	fin>>m>>n;
	for(int i = 1; i<= m ;i++)
		fin>> v[i];
	for(int i = 1; i<= n ;i++)
		fin>> u[i];
	fin.close();
}

void dinamica(){
	for(int i =1 ;i<=m;i++)
		for(int j=1;j<=n;j++){
			a[i][j] = a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
			if(v[i] == u[j])
				a[i][j] ++;
		}
}

void write(){
	ofstream fout("cmlsc.out");
	fout<<a[m][n]<<endl;
	int sol[MAX], nrsol=0;
	int i = m, j=n;
	while(i*j){
		if(v[i] == u[j])
			sol[++nrsol]=v[i], i--,j--;
		else
			if(a[i][j]==a[i-1][j])
				i--;
			else
				j--;
	}
	for(i = nrsol; i ;i--)
		fout<<sol[i]<<" ";
	fout.close();
}

int main(){
	read();
	dinamica();
	write();
	return 0;
}
