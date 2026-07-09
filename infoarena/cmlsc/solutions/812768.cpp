#include<iostream>
#include<fstream>
using namespace std;
#define MAX_N 1500

int N, M; // lungimile celor doua siruri
int a[MAX_N], b[MAX_N]; // cele doua siruri
int stack[MAX_N], vizitat[MAX_N], maxim;
void read(){
	ifstream f("cmlsc.in");
	
	f >> N >> M;
	
	for(int i=1; i<=N; i++){
		f >> a[i];
	}
	for(int i=1; i<=M; i++){
		f >> b[i];
	}
}


void LCS(int size_a, int size_b){
	
	
	if(size_a && size_b){
		
		if(a[size_a] == b[size_b]){
			if(!vizitat[size_a]){
				stack[++stack[0]] = a[size_a];
				vizitat[size_a] = 1;
				maxim ++;
				LCS(size_a-1,size_b-1);
			}
		
		}else{
			LCS(size_a-1,size_b);
			LCS(size_a, size_b-1);
		}
		
	}

}

int main(){
	
	read();
	LCS(N,M);
	
	ofstream g("cmlsc.out");
	g << maxim << '\n';
	for(int i=stack[0]; i>=1 ; i--){
		g << stack[i] << " ";
	}

	return 0;
}
